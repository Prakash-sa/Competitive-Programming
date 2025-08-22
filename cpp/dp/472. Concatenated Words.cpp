/*
https://leetcode.com/problems/concatenated-words/description/

Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.



Example 1:
Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
"dogcatsdog" can be concatenated by "dog", "cats" and "dog";
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".


Example 2:
Input: words = ["cat","dog","catdog"]
Output: ["catdog"]
*/

class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        unordered_set<string> word_set;
        for (auto word : words)
            word_set.insert(word);

        vector<string> res;
        for (auto word : word_set)
        {
            int n = word.size();
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            for (int i = 0; i < n; i++)
            {
                if (!dp[i])
                    continue;
                for (int j = i + 1; j <= n; j++)
                {
                    if (j - i < n && word_set.count(word.substr(i, j - i)))
                    {
                        dp[j] = 1;
                    }
                }
                if (dp[n])
                {
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};