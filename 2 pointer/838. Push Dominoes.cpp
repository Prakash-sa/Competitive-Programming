//https://leetcode.com/problems/push-dominoes/


/*
There are n dominoes in a line, and we place each domino vertically upright. 
In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
After each second, each domino that is falling to the left pushes the adjacent domino on the left. 
Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.
 

Example 1:
Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.

Example 2:
Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
*/


class Solution {
    
    string s;
    void add(int cnt,char c){
        for(int i=0;i<cnt;i++)s+=c;
    }
    
public:
    string pushDominoes(string d) {
        s="";
        int count=0;
        char last='L';
        for(int i=0;i<d.size();i++){
            if(d[i]!='.'){
                if(d[i]==last){
                    add(count,last);
                }
                else if(last=='L'){
                    add(count,'.');
                }
                else {
                    add(count/2,'R');
                    if(count%2!=0)s+='.';
                    add(count/2,'L');
                    
                }
                s+=d[i];
                last=d[i];
                count=0;
            }
            else {
                count++;
            }
        }
        
        add(count,last=='R'?'R':'.');
        
        return s;
    }
};