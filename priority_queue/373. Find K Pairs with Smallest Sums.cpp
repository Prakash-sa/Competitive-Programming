/*
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
Define a pair (u, v) which consists of one element from the first array and one element from the second array.
Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

Example 1:
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:
Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

Example 3:
Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
*/

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> arr;
        int m = nums1.size(), n = nums2.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> res;
        if (m == 0 || n == 0)
            return res;

        for (int i = 0; i < m; i++)
        {
            pq.push({{nums1[i] + nums2[0]}, {i, 0}});
        }
        while (!pq.empty() && k-- > 0)
        {
            int val = pq.top().first, i = pq.top().second.first, j = pq.top().second.second;
            pq.pop();
            vector<int> v = {nums1[i], nums2[j]};
            res.push_back(v);
            if (j + 1 == n)
                continue;
            pq.push({{nums1[i] + nums2[j + 1]}, {i, j + 1}});
        }
        return res;
    }
};