## Problems 

- Dice Throw Problem: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
- Coin Change: https://leetcode.com/problems/coin-change/ and https://leetcode.com/problems/coin-change-2/
- Counting Boolean Parenthesizations:
- Subset Sum Problem:
- Minimum Number of Jumps: https://leetcode.com/problems/jump-game-ii/
- Two-Person Traversal of a Sequence of Cities:
- Balanced Partition: https://leetcode.com/problems/partition-equal-subset-sum/
- Optimal Strategy for a Game: https://leetcode.com/problems/predict-the-winner/
- Maximum Value Contiguous Subsequence: https://leetcode.com/problems/maximum-subarray/
- Edit Distance: https://leetcode.com/problems/edit-distance/


# knapsack 

1. 1-0
- Initialize array with 0

    for (int i = 1; i <= n; i++)
    {
        for (w = 1; w <= W; w++)
        {
            dp[i][w] = dp[i-1][w];  //don't include the item
            if (wt[i-1] <= w)
                    dp[i][w] = max(dp[i][w], val[i-1] + dp[i-1][w-wt[i-1]]);  
        }
    }

2. Fractional Knapsack

- sort the array with comparision.

bool cmp(struct Item a, struct Item b) 
{ 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 
    return r1 > r2; 
} 

- add the results till W.





# Buy and sell

simple for loop


# Coin Change 

1. Minimum

- Initialize dp with 0
- assign x-axis 0 value and y-axis max value.
- answer is dp[n2][n1].

    for(int i=1;i<=n2;i++){
        for(int j=1;j<=n1;j++){
            if(j<a[i-1])dp[i][j]=dp[i-1][j];
            else dp[i][j]=min(dp[i-1][j],dp[i][j-a[i-1]]+1);
        }
    }

2. Number

- Initialize dp with 0
- assign x-axis 1 value
- answer is dp[n][k]

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j<a[i-1])dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i-1][j]+dp[i][j-a[i-1]];
        }
    }


# Coin Game winner

- 


# Gold Mine Problem

- Initialize the dp with 0
- Go right, right_up and right_down.

    for (int col=n-1; col>=0; col--) 
    { 
        for (int row=0; row<m; row++) 
        { 
            int right = (col==n-1)? 0: goldTable[row][col+1]; 
            int right_up = (row==0 || col==n-1)? 0:goldTable[row-1][col+1]; 
            int right_down = (row==m-1 || col==n-1)? 0:goldTable[row+1][col+1]; 
            goldTable[row][col] = dp[row][col] + max(right, max(right_up, right_down)); 
        } 
    }

- Answer will be in goldTable[n-1][0].


# Edit Distance

- Initialize dp with 0.
- Assign x-axis with i and y-axis with i.
- (i-1,j-1) for , (i-1,j) for ,(j,i-1) for
- answer is dp[m][n].


    for(int i=1;i<=m;i++)dp[i][0]=i;
    for(int i=1;i<=n;i++)dp[0][i]=i;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
        }
    }


# Egg Dropping 

- Initialize dp with -1.
- Apply binary search from 1 to k.
- 

    if(k==1 || k==0)return dp[n][k]=k;
    if(n==1)return dp[n][k]=k;

- Assign x the value when egg brokes and y the value when it didn't.
- store the max value of x and y in res variable. 

    int l=1,r=k;
    while(l<=r){
        int mid=(l+r)/2;
        int x=eggDrop(n-1,mid-1),y=eggDrop(n,k-mid);
        res=min(res,1+max(x,y));
        if(x<y)l=mid+1;
        else r=mid-1;
    }
    return dp[n][k]=res;


# Interleaves String

- Initialize dp with 0.
- Answer will be in dp[n][m];

```
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if (i==0 && j==0) 
                IL[i][j] = true; 
  
            // A is empty 
            else if (i==0 && B[j-1]==C[j-1]) 
                IL[i][j] = IL[i][j-1]; 
  
            // B is empty 
            else if (j==0 && A[i-1]==C[i-1]) 
                IL[i][j] = IL[i-1][j]; 
  
            // Current character of C matches with current character of A, 
            // but doesn't match with current character of B 
            else if(A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1]) 
                IL[i][j] = IL[i-1][j]; 
  
            // Current character of C matches with current character of B, 
            // but doesn't match with current character of A 
            else if (A[i-1]!=C[i+j-1] && B[j-1]==C[i+j-1]) 
                IL[i][j] = IL[i][j-1]; 
  
            // Current character of C matches with that of both A and B 
            else if (A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1]) 
                IL[i][j]=(IL[i-1][j] || IL[i][j-1]) ; 
        }
    }
```


# Jump game

1. 

2. 

3. 

4. 

5.

6.

7.



# Kadane

1. Max Sum
- Store the local and global variable.
- Answer will be in the global.

    int lo=a[0],go=a[0];
    for(int i=1;i<n;i++){
        lo=max(a[i],a[i]+lo);
        go=max(go,lo);
    }
    

2. Max Product
- Store the minimum and maximum number from the array.
- Swap the min and max when negative number occur.


    int ans=nums[0],maxm=nums[0],minm=nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]<0){
            swap(maxm,minm);
        }
        maxm=max(nums[i],nums[i]*maxm);
        minm=min(nums[i],nums[i]*minm);
        ans=max(ans,maxm);
    }




# Subsequences

1. Longest Palindromic Subsequence:-

- Initialize dp with 0.
- answer is dp[0][n-1].

    for(long long int k=0;k<n;k++){
        long long int i=0;
        for(long long int j=k;j<n;j++){
            if(i==j)dp[i][j]=1;
            else if(j==i+1)dp[i][j]=str[i]==str[j]?3:2;
            else {
                if(str[i]==str[j])dp[i][j]=(dp[i][j-1]+dp[i+1][j]+1)%mod;
                else dp[i][j]=(mod+dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1])%mod;
            }
            i++;
        }
    }

2. Longest Common Subsequence of 3 string 

- Same as LCS of 2 string.

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=n1;k++){
                if(i==0||j==0||k==0)dp[i][j][k]=0;
                else if(s1[i-1]==s2[j-1]&&s1[i-1]==s3[k-1])dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                else dp[i][j][k]=max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
            }
        }
    }



# Larget Divisible Subset

- Initialize dp with 1.
- Iterate through array two times.
- Store the divisible number.

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                pre_node[i]=j;
            }
        }
        if(dp[i]>dp[max_in])max_in=i;
    }

- 
    int t=max_in;
    while(t>=0){
        ans.push_back(nums[t]);
        t=pre_node[t];
    }


# Larget Rectanle Sub Matrix with sum 0

