#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool isUpcase(char c){
    return (c >= 'A') && (c <= 'Z');
}

char upcase(char c){
    if (isUpcase(c)) return c;
    return (char)(c - 32);
}

bool dp[1011][1011];

int main() {
    int test;
    cin >> test;

    while(test--) {
        string s1, s2;
        cin >> s1;
        cin >> s2;

        for(int i = 0; i <= s1.length(); i++) {
            for(int j = 0; j <= s2.length(); j++) {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;

        for (int i = 0; i < s1.length(); i++){
            for (int j = 0; j <= s2.length(); j++)if (dp[i][j]){
                if(j < s2.length() && (upcase(s1[i]) == s2[j]))dp[i + 1][j + 1] = true;
                if(!isUpcase(s1[i])) dp[i + 1][j] = true;
            }
        }

        if (dp[s1.length()][s2.length()]) cout << "YES" << endl; else cout << "NO" << endl;
    }
}
