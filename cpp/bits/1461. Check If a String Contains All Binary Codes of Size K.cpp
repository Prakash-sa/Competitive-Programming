//https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

/*

Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. 
Otherwise, return false.

Example 1:

Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". 
They can be all found as substrings at indices 0, 1, 3 and 2 respectively.



What's more, we can get the current hash from the last one. 
This method is called Rolling Hash. All we need to do is to remove the most significant digit and to add a new least significant digit with bitwise operations.

*/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need=1<<k;
        vector<bool>got(need,false);
        int allone=need-1;
        int hashVal=0;
        for(int i=0;i<s.size();i++){
            hashVal=((hashVal<<1)&allone)|(s[i]-'0');
            if(i>=k-1 && !got[hashVal]){
                need--;
                got[hashVal]=true;
                if(need==0)return true;
            }
        }
        return false;
    }
};
