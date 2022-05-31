/*
For a = 1, b = 1, and c = 1, the output should be
calculationsWithCoins(a, b, c) = 3.

Here are all possible combinations:

* a = b = c = 1
* a + b = a + c = b + c = 1 + 1 = 2
* a + b + c = 1 + 1 + 1 = 3
For a = 1, b = 2, and c = 4, the output should be
calculationsWithCoins(a, b, c) = 7.

Here are all possible combinations:

* a = 1
* b = 2
* a + b = 1 + 2 = 3
* c = 4
* a + c = 1 + 4 = 5
* b + c = 2 + 4 = 6
* a + b + c = 1 + 2 + 4 = 7
*/

int calculationsWithCoins(int a, int b, int c) {
    set<int>s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(a+b);
    s.insert(b+c);
    s.insert(c+a);
    s.insert(a+b+c);
    return s.size();
    

}

