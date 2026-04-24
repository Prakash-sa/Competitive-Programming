# https://leetcode.com/problems/print-zero-even-odd/description/?envType=problem-list-v2&envId=concurrency

'''
You have a function printNumber that can be called with an integer parameter and prints it to the console.

For example, calling printNumber(7) prints 7 to the console.
You are given an instance of the class ZeroEvenOdd that has three functions: zero, even, and odd. The same instance of ZeroEvenOdd will be passed to three different threads:

Thread A: calls zero() that should only output 0's.
Thread B: calls even() that should only output even numbers.
Thread C: calls odd() that should only output odd numbers.
Modify the given class to output the series "010203040506..." where the length of the series must be 2n.

Implement the ZeroEvenOdd class:

ZeroEvenOdd(int n) Initializes the object with the number n that represents the numbers that should be printed.
void zero(printNumber) Calls printNumber to output one zero.
void even(printNumber) Calls printNumber to output one even number.
void odd(printNumber) Calls printNumber to output one odd number.
 

Example 1:
Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously.
One of them calls zero(), the other calls even(), and the last one calls odd().
"0102" is the correct output.
Example 2:
Input: n = 5
Output: "0102030405"

Constraints:
1 <= n <= 1000
'''


from threading import Lock

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.last_count=0
        self.zero_lock=Lock()
        self.even_lock=Lock()
        self.odd_lock=Lock()
        self.even_lock.acquire()
        self.odd_lock.acquire()

    # printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for _ in range(self.n):
            self.zero_lock.acquire()
            printNumber(0)
            self.last_count+=1
            if self.last_count%2:
                self.odd_lock.release()
            else:
                self.even_lock.release()
        
    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for _ in range(self.n//2):
            self.even_lock.acquire()
            printNumber(self.last_count)
            self.zero_lock.release()
            
        
    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for _ in range((self.n+1)//2):
            self.odd_lock.acquire()
            printNumber(self.last_count)
            self.zero_lock.release()
            


'''
Time Complexity
Let n = number of integers to print.
Total prints required:
0 1 0 2 0 3 ... 0 n

So total prints = 2n
Breakdown by threads:
zero() runs n times
odd() runs ⌈n/2⌉ times
even() runs ⌊n/2⌋ times

Each iteration only performs:
one acquire
one release
one print

All are O(1) operations.
Therefore
Time Complexity = O(n)
because total operations scale linearly with n.
Space Complexity
We only store:
n
last_count
three locks
No arrays, lists, or additional structures.

So:
Space Complexity = O(1)
constant memory regardless of n.
Concurrency Note (important in interviews)

Even though there are 3 threads, the locks enforce strict sequential execution:
zero -> odd/even -> zero -> odd/even
So effective execution is serialized, not parallel.
Final Answer (interview style)
Time Complexity:  O(n)
Space Complexity: O(1)

because each number from 1..n is processed once and the algorithm only uses constant auxiliary memory.
'''

