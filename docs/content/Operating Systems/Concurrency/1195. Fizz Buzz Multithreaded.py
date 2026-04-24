# https://leetcode.com/problems/fizz-buzz-multithreaded/description/?envType=problem-list-v2&envId=concurrency

'''
You have the four functions:
printFizz that prints the word "fizz" to the console,
printBuzz that prints the word "buzz" to the console,
printFizzBuzz that prints the word "fizzbuzz" to the console, and
printNumber that prints a given integer to the console.
You are given an instance of the class FizzBuzz that has four functions: fizz, buzz, fizzbuzz and number. The same instance of FizzBuzz will be passed to four different threads:
Thread A: calls fizz() that should output the word "fizz".
Thread B: calls buzz() that should output the word "buzz".
Thread C: calls fizzbuzz() that should output the word "fizzbuzz".
Thread D: calls number() that should only output the integers.
Modify the given class to output the series [1, 2, "fizz", 4, "buzz", ...] where the ith token (1-indexed) of the series is:
"fizzbuzz" if i is divisible by 3 and 5,
"fizz" if i is divisible by 3 and not 5,
"buzz" if i is divisible by 5 and not 3, or
i if i is not divisible by 3 or 5.
Implement the FizzBuzz class:
FizzBuzz(int n) Initializes the object with the number n that represents the length of the sequence that should be printed.
void fizz(printFizz) Calls printFizz to output "fizz".
void buzz(printBuzz) Calls printBuzz to output "buzz".
void fizzbuzz(printFizzBuzz) Calls printFizzBuzz to output "fizzbuzz".
void number(printNumber) Calls printnumber to output the numbers. 

Example 1:
Input: n = 15
Output: [1,2,"fizz",4,"buzz","fizz",7,8,"fizz","buzz",11,"fizz",13,14,"fizzbuzz"]

Example 2:
Input: n = 5
Output: [1,2,"fizz",4,"buzz"]

Constraints:
1 <= n <= 50
'''

'''
Explanation
Semaphore(1) can be used to replace Lock(), therefore 5 approaches
Very similar to 1116. Print Zero Even Odd
Make sure we have control over the executing order by using Lock/Semaphore/Condition/Lock.
The Barrier solution is slightly different, as it doens't really care about the executing order, but keep 4 threads in sync for each iteration. The performance might compromise a little bit as it's running more iterations than other solutions.
Approaches #1 & 2. Lock/Semaphore
'''

from threading import Lock
class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        self.fifteen = self.n // 15
        self.three = self.n // 3 - self.fifteen
        self.five = self.n // 5 - self.fifteen
        self.rest = self.n - self.three - self.fifteen - self.five
        self.fl = Lock()  # Semaphore(1)
        self.bl = Lock()  # Semaphore(1)
        self.fbl = Lock() # Semaphore(1)
        self.nl = Lock()  # Semaphore(1)
        self.fl.acquire()
        self.bl.acquire()
        self.fbl.acquire()
        self.cur = 1

    def release_lock(self, is_number_thread=False):
        if self.cur % 15 == 0:
            self.fbl.release()
        elif self.cur % 3 == 0:
            self.fl.release()
        elif self.cur % 5 == 0:
            self.bl.release()
        else:
            if not is_number_thread:
                self.nl.release()
            return True
        return False

    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        for _ in range(self.three):
            with self.fl:
                printFizz()
                self.cur += 1
                self.release_lock()
            self.fl.acquire()    

    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        for _ in range(self.five):
            with self.bl:
                printBuzz()
                self.cur += 1
                self.release_lock()
            self.bl.acquire()    

    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        for _ in range(self.fifteen):
            with self.fbl:
                printFizzBuzz()
                self.cur += 1
                self.release_lock()
            self.fbl.acquire()    
        
    def number(self, printNumber: 'Callable[[int], None]') -> None:
        for _ in range(self.rest):
            again = True 
            with self.nl:
                printNumber(self.cur)
                self.cur += 1
                again = self.release_lock(is_number_thread=True)
            if not again:
                self.nl.acquire()     

# Approaches #3. Condition

from threading import Condition
class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        self.c = Condition()
        self.cur = 1
        self.fb_cnt = n // 15
        self.fizz_cnt = n // 3 - self.fb_cnt
        self.buzz_cnt = n // 5 - self.fb_cnt
        self.other = n - self.fb_cnt - self.fizz_cnt - self.buzz_cnt

    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        for _ in range(self.fizz_cnt):
            with self.c:
                self.c.wait_for(lambda: self.cur % 3 == 0 and self.cur % 5 != 0)
                printFizz()
                self.cur += 1
                self.c.notify_all()

    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        for _ in range(self.buzz_cnt):
            with self.c:
                self.c.wait_for(lambda: self.cur % 3 != 0 and self.cur % 5 == 0)
                printBuzz()
                self.cur += 1
                self.c.notify_all()

    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        for _ in range(self.fb_cnt):
            with self.c:
                self.c.wait_for(lambda: self.cur % 15 == 0)
                printFizzBuzz()
                self.cur += 1
                self.c.notify_all()
        
    def number(self, printNumber: 'Callable[[int], None]') -> None:
        for _ in range(self.other):
            with self.c:
                self.c.wait_for(lambda: self.cur % 15 and self.cur % 3 and self.cur % 5)
                printNumber(self.cur)
                self.cur += 1
                self.c.notify_all()

# Approaches #4. Event

from threading import Event

class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        self.ef = Event()
        self.eb = Event()
        self.efb = Event()
        self.en = Event()
        self.cur = 1
        self.fb_cnt = n // 15
        self.fizz_cnt = n // 3 - self.fb_cnt
        self.buzz_cnt = n // 5 - self.fb_cnt
        self.other = n - self.fb_cnt - self.fizz_cnt - self.buzz_cnt

    def set_flag(self):
        if self.cur % 15 == 0:
            self.efb.set()
        elif self.cur % 5 == 0:
            self.eb.set()
        elif self.cur % 3 == 0:
            self.ef.set()
        else:
            self.en.set()


    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        for _ in range(self.fizz_cnt):
            while not (self.cur % 3 == 0 and self.cur % 5 != 0):
                self.ef.wait()
            printFizz()
            self.cur += 1
            self.ef.clear()
            self.set_flag()

    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        for _ in range(self.buzz_cnt):
            while not (self.cur % 3 != 0 and self.cur % 5 == 0):
                self.eb.wait()
            printBuzz()
            self.cur += 1
            self.eb.clear()
            self.set_flag()

    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        for _ in range(self.fb_cnt):
            while not (self.cur % 15 == 0):
                self.efb.wait()
            printFizzBuzz()
            self.cur += 1
            self.efb.clear()
            self.set_flag()
        

    def number(self, printNumber: 'Callable[[int], None]') -> None:
        for _ in range(self.other):
            while not (self.cur % 15 and self.cur % 3 and self.cur % 5):
                self.en.wait()
            printNumber(self.cur)
            self.cur += 1
            self.en.clear()
            self.set_flag()

# Approaches #5. Barrier

from threading import Barrier
class FizzBuzz:
    def __init__(self, n: int):
        self.n = n + 1
        self.br = Barrier(4)

    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        for cur in range(1, self.n):
            if cur % 3 == 0 and cur % 5 != 0:
                printFizz()
            self.br.wait()

    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        for cur in range(1, self.n):
            if cur % 3 != 0 and cur % 5 == 0:
                printBuzz()
            self.br.wait()

    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        for cur in range(1, self.n):
            if cur % 3 == 0 and cur % 5 == 0:
                printFizzBuzz()
            self.br.wait()

    def number(self, printNumber: 'Callable[[int], None]') -> None:
        for cur in range(1, self.n):
            if cur % 3 != 0 and cur % 5 != 0:
                printNumber(cur)
            self.br.wait()
