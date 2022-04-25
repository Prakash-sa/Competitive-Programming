//https://practice.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1/#



class Solution {
    
    vector<int> computeLPSArray(string str)
    {
        int M = str.length();
        vector<int> lps(M);
     
        int len = 0;
        lps[0] = 0;
     
        int i = 1;
        while (i < M)
        {
            if (str[i] == str[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else 
            {
                if (len != 0)
                {
                    len = lps[len-1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
public:
    int minChar(string str){
       string revStr = str;
        reverse(revStr.begin(), revStr.end());
     
        string concat = str + "$" + revStr;
     
        vector<int> lps = computeLPSArray(concat);
     
        return (str.length() - lps.back());
    }
};

