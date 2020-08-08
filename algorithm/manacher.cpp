#include <bits/stdc++.h>
using namespace std;
#define SIZE 10000000 + 1
typedef long long int lli;

lli P[SIZE * 2];

// Transform S into new string with special characters inserted.
string convertToNewString(const string &s) {
    string newString = "@";

    for (lli i = 0; i < s.size(); i++) {
        newString += "#" + s.substr(i, 1);
    }

    newString += "#$";
    return newString;
}

string longestPalindromeSubstring(const string &s) {
    string Q = convertToNewString(s);
    lli c = 0, r = 0;                // current center, right limit

    for (lli i = 1; i < Q.size() - 1; i++) {
        lli iMirror = c - (i - c);

        if(r > i) {
            P[i] = min(r - i, P[iMirror]);
        }

        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }

        if (i + P[i] > r) {
            c = i;              // next center = i
            r = i + P[i];
        }
    }
    lli maxPalindrome = 0;
    lli centerIndex = 0;

    for (lli i = 1; i < Q.size() - 1; i++) {

        if (P[i] > maxPalindrome) {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }
    int count=0;
    for(lli i=0;i<SIZE*2;i++){
        if(P[i]>=2)count++;
    }
    cout<<count;
    cout << maxPalindrome << "\n";
    return s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
}

int main() {
    string s;
    cin>>s;
    cout << longestPalindromeSubstring(s);
}