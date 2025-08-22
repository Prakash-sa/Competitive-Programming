//https://leetcode.com/problems/count-different-palindromic-subsequences/

//https://www.youtube.com/watch?v=fvYlinirmFg&ab_channel=Pepcoding







class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int N = S.size();
        long MOD = 1e9 + 7;
        
        vector<vector<int>> T(N, vector<int>(N, 0));
        
        for (int i = 0; i < N; ++i)
            T[i][i] = 1;
        
        for (int gap = 1; gap < N; ++gap) {
            for (int i = 0, j = i+gap; j < N; ++i, ++j) {
                //Fill in T[i][j]
                if (S[i] != S[j]) {
                    T[i][j] = T[i+1][j] + T[i][j-1] - T[i+1][j-1];
                } else {
                    // Si, Si+1, ..., Sj-1, Sj
                    // Si+1, ...., Sj-1
                    T[i][j] = 2 * T[i+1][j-1];
                    
                    int l = i+1, r = j-1;
                    while(l <= r && S[l] != S[i]) l++;
                    while(l <= r && S[r] != S[i]) r--;
                    
                    if (l < r) {
                        // S(i, j) = b # # b . . b # # b where # != b
                        T[i][j] -= T[l+1][r-1];   
                    }
                    
                    if (l == r) {
                        // S(i, j) = b # # b # # b where # != b
                        T[i][j] += 1;
                    }
                    
                    if (l > r) {
                        // S(i, j) = b # # # b where # != b
                        T[i][j] += 2;
                    }
                }
                T[i][j] = (T[i][j] + MOD)%MOD;
            }
        }
        
        return T[0][N-1];
    }
};
