// https://leetcode.com/problems/insert-interval/description/

/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.



Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

*/

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int start = newInterval[0], end = newInterval[1];
        vector<vector<int>> ans;
        int first = false;
        if (intervals.size() == 0)
            return {newInterval};
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][1] < start)
            {
                ans.push_back(intervals[i]);
            }
            else if (intervals[i][0] > end)
            {
                if (!first)
                {
                    ans.push_back({start, end});
                    first = true;
                }
                ans.push_back(intervals[i]);
            }
            else
            {
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }
        if (!first)
            ans.push_back({start, end});
        return ans;
    }
};