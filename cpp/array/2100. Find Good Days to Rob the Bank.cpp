//https://leetcode.com/problems/find-good-days-to-rob-the-bank/


/*
You and a gang of thieves are planning on robbing a bank. 
You are given a 0-indexed integer array security, where security[i] is the number of guards on duty on the ith day. 
The days are numbered starting from 0. You are also given an integer time.

The ith day is a good day to rob the bank if:

There are at least time days before and after the ith day,
The number of guards at the bank for the time days before i are non-increasing, and
The number of guards at the bank for the time days after i are non-decreasing.

More formally, this means day i is a good day to rob the bank if and only 
if security[i - time] >= security[i - time + 1] >= ... >= security[i] <= ... <= security[i + time - 1] <= security[i + time].
*/


class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int>res;
        int n=security.size();
        vector<int>left(n,0),right(n,0);
        for(int i=1;i<n;i++){
            if(security[i]<=security[i-1])left[i]=1+left[i-1];
        }
        for(int i=n-2;i>=0;i--){
            if(security[i+1]>=security[i])right[i]=1+right[i+1];
        }
        for(int i=0;i<n;i++){
            if(left[i]>=time && right[i]>=time)res.push_back(i);
        }
        return res;
    }
};
