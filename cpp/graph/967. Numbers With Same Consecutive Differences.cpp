//https://leetcode.com/problems/numbers-with-same-consecutive-differences/


/*
Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.
Note that every number in the answer must not have leading zeros. 
For example, 01 has one leading zero and is invalid.
You may return the answer in any order.
 

Example 1:

Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
*/

class Solution {
    
    void make(int num,int k,int n,vector<int>&res){
        if(n==0){
            res.push_back(num);
            return;
        }
        
        int digit=num%10;
        if(digit+k<=9){
            make(num*10+digit+k,k,n-1,res);
        }
        if(k!=0 && digit-k>=0){
            make(num*10+digit-k,k,n-1,res);
        }
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res;
        for(int i=1;i<=9;i++){
          make(i,k,n-1,res);  
        }
        return res;
    }
};

