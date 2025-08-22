//https://leetcode.com/problems/stamping-the-sequence/


/*
You are given two strings stamp and target. Initially, there is a string s of length target.length with all s[i] == '?'.

In one turn, you can place stamp over s and replace every letter in the s with the corresponding letter from stamp.
    For example, if stamp = "abc" and target = "abcba", then s is "?????" initially. In one turn you can:
        place stamp at index 0 of s to obtain "abc??",
        place stamp at index 1 of s to obtain "?abc?", or
        place stamp at index 2 of s to obtain "??abc".
    Note that stamp must be fully contained in the boundaries of s in order to stamp (i.e., you cannot place stamp at index 3 of s).
We want to convert s to target using at most 10 * target.length turns.
Return an array of the index of the left-most letter being stamped at each turn. 
If we cannot obtain target from s within 10 * target.length turns, return an empty array.
 

Example 1:

Input: stamp = "abc", target = "ababc"
Output: [0,2]
Explanation: Initially s = "?????".
- Place stamp at index 0 to get "abc??".
- Place stamp at index 2 to get "ababc".
[1,0,2] would also be accepted as an answer, as well as some other answers.
*/


class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int>res;
        int total_stamp=0,turn_stamp=-1;
        while(turn_stamp){
            turn_stamp=0;
            for(int sz=stamp.size();sz>0;sz--){
                for(int i=0;i<=stamp.size()-sz;i++){
                    string new_stamp=string(i,'*')+stamp.substr(i,sz)+string(stamp.size()-sz-i,'*');
                    auto pos=target.find(new_stamp);
                    while(pos!=string::npos){
                        res.push_back(pos);
                        turn_stamp+=sz;
                        fill(begin(target)+pos,begin(target)+pos+stamp.size(),'*');
                        pos=target.find(new_stamp);
                    }
                }
            }
            total_stamp+=turn_stamp;
        }
        reverse(begin(res),end(res));
        return total_stamp==target.size()?res:vector<int>();
    }
};
