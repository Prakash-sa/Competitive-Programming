/*
https://leetcode.com/problems/satisfiability-of-equality-equations/

You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and 
takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.
Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

Example 1:

Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.
Example 2:

Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

Union find
*/


class Solution {
    int uf[26];
public:
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<26;i++)uf[i]=i;
        for(auto e:equations){
            if(e[1]=='='){
                uf[find(e[0]-'a')]=uf[find(e[3]-'a')];
            }
        }
        for(auto e:equations){
            if(e[1]=='!' && find(e[0]-'a')==find(e[3]-'a')){
                return false;
            }
        }
        return true;
    }
    
    int find(int x){
        if(x!=uf[x])uf[x]=find(uf[x]);
        return uf[x];
    }
    
};