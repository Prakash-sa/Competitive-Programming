//https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1#

//KMP Algo








class Solution{
    
  public:		
	int lps(string s) {
	    // Your code goes here
	    vector<int>dp(s.size(),0);
	    int i=1,j=0;
	    while(i<s.size()){
	        if(s[i]==s[j]){
	            dp[i]=j+1;
	            j++;
	            i++;
	        }
	        else {
	            if(j==0)i++;
	            else j=dp[j-1];
	        }
	    }
	    
	    return dp.back();
	}   
};








//https://leetcode.com/problems/implement-strstr/







class Solution {
public:
    int strStr(string haystack, string needle) {
        int nsize = needle.size();
    	int hsize = haystack.size();
    	if (nsize == 0) return 0;
    	int *table = new int[nsize];
    	memset(table, 0, sizeof(int)*nsize);
    	//building match table
    	for (int i = 1, j = 0; i < nsize - 1;){
    		if (needle[i] != needle[j]){
    			if (j>0){
    				j = table[j - 1];
    			}
    			else{
    				i++;
    			}
    		}
    		else{
    			table[i] = j + 1;
    			i++;
    			j++;
    		}
    	}
    	//matching
    	for (int i = 0, match_pos = 0; i < hsize;){
    		if (haystack[i] == needle[match_pos]){
    			if (match_pos == nsize - 1){
    				return i - (nsize - 1);
    			}
    			else{
    				i++;
    				match_pos++;
    			}
    		}
    		else{
    			if (match_pos == 0){
    				i++;
    			}
    			else{
    				match_pos = table[match_pos - 1];
    			}
    		}
    	}
    	delete[]table;
    	return -1;
    }
};
