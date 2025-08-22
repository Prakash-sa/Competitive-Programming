//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

/*
You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, 
causing the left and the right side of the deleted substring to concatenate together.
We repeatedly make k duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. 
It is guaranteed that the answer is unique.

 

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && st.top().first==s[i]){
                ++st.top().second;
            }
            else st.push({s[i],1});
            
            if(st.top().second==k)st.pop();
        }
        
        string output="";
        while(!st.empty()){
            while(st.top().second>0){
                output+=st.top().first;
                --st.top().second;
            }
            st.pop();
        }
        
        reverse(output.begin(),output.end());
        return output;
    }
};
