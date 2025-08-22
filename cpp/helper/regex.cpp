#include <set>
#include <iostream>
#include <regex>
using namespace std;

int main()
{
    int N;
    cin >> N;
    regex e(".+@gmail\\.com$");
    multiset<string> db;
    for(int a0 = 0; a0 < N; a0++)
    {
        string firstName;
        string emailID;
        cin >> firstName >> emailID;
        if(regex_match(emailID,e))
        {
            db.insert(firstName);
        }
    }
    // just a fancy and less robust way of iterating in 
    // C++11 (and later)
    for(auto& it : db) 
    { 
        cout << it << endl; 
    }
    return 0;
}