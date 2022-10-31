// https://leetcode.com/problems/remove-invalid-parentheses/

class Solution
{
public:
    // no. of char to remove
    int check(string s)
    {
        stack<char> st;
        for (auto c : s)
        {
            if (c == '(')
                st.push(c);
            else if (c == ')' && st.size() > 0 && st.top() == '(')
                st.pop();
            else if (c == ')')
                st.push(c);
        }

        return st.size();
    }

    vector<string> removeInvalidParentheses(string s)
    {
        int n = s.size(), w = check(s);
        vector<string> ans;
        queue<string> q;
        unordered_set<string> hash;
        q.push(s);

        while (!q.empty())
        {
            string k = q.front();
            q.pop();
            if (hash.find(k) == hash.end())
            {
                hash.insert(k);
            }
            else
            {
                continue;
            }
            if (check(k) == 0)
            {
                ans.push_back(k);
            }
            else
            {
                for (int i = 0; i < k.size(); i++)
                {
                    string tmp = k.substr(0, i) + k.substr(i + 1);
                    if (tmp.size() >= n - w)
                        q.push(tmp);
                }
            }
        }

        return ans;
    }
};
