//https://www.geeksforgeeks.org/minimum-number-deletions-make-string-palindrome/


#include<bits/stdc++.h>
using namespace std;

int dp[2000][2000];

// Function definition
int transformation(string s1, string s2,
				int i, int j)
{
	
	// Base cases
	if (i >= (s1.size()) || j >= (s2.size()))
		return 0;
	
	// Checking the ndesired condition
	if (s1[i] == s2[j])
	{
		
		// If yes increment the count
		dp[i][j] = 1 + transformation(s1, s2, i + 1,
											j + 1);
	}
	
	// If no
	if (dp[i][j] != -1)
	{
		
		// Return the value form the table
		return dp[i][j];
	}
	
	// Else store the max transformation
	// from the subsequence
	else
		dp[i][j] = max(transformation(s1, s2, i, j + i),
					transformation(s1, s2, i + 1, j));
	
	// Return the dp [-1][-1]
	return dp[s1.size() - 1][s2.size() - 1];
}

// Driver code
int main()
{
	string s1 = "geeksforgeeks";
	string s2 = "geeks";
	int i = 0;
	int j = 0;
	
	// Initialize the array with -1
	memset(dp, -1, sizeof dp);
	
	cout << "MINIMUM NUMBER OF DELETIONS: "
		<< (s1.size()) - transformation(s1, s2, 0, 0)
		<< endl;
	cout << "MINIMUM NUMBER OF INSERTIONS: "
		<< (s2.size()) - transformation(s1, s2, 0, 0)
		<< endl;
	cout << ("LCS LENGTH: ")
		<< transformation(s1, s2, 0, 0);
}

// This code is contributed by Stream_Cipher

