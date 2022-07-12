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
- https://codeforces.com/blog/entry/43256
- https://atcoder.jp/contests/dp/tasks


# knapsack 

- 1-0
    - Initialize array with 0

```
for (int i = 1; i <= n; i++){
    for (w = 1; w <= W; w++){
        dp[i][w] = dp[i-1][w];  //don't include the item
        if (wt[i-1] <= w)
                dp[i][w] = max(dp[i][w], val[i-1] + dp[i-1][w-wt[i-1]]);  
    }
}
```

- Fractional Knapsack

    - sort the array with comparision.

```
bool cmp(struct Item a, struct Item b) 
{ 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 
    return r1 > r2; 
} 
```

    - add the results till W.

- Product Subsequence count

    - Same as sum

```
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
        // number of subsequence using i-1 terms
        dp[i][j] = dp[i-1][j];

        // if arr[i-1] > j it will surely make product greater
        // thus it won't contribute then
        if (arr[i - 1] <= j)
            // number of subsequence using 1 to i-1 terms
            // and i-th term
            dp[i][j] += dp[i-1][j/arr[j-1]] + 1;
    }
}
```


# Subset Sum

- Initialize dp with -1. 
- Return false if sum is odd.
- Assign the dp value based on inclusion and exclusion.

```
if(n<=0&&sum!=0)return 0;
if(sum<0)return 0;
if(sum==0)return 1;
if(dp[n-1][sum]!=-1)return dp[n-1][sum];

int ans=ch(a,n-1,sum-a[n-1])||ch(a,n-1,sum);
dp[n-1][sum]=ans;
```





# Buy and sell

simple for loop



# Coin Change 

1. Minimum

- Initialize dp with 0
- assign x-axis 0 value and y-axis max value.
- answer is dp[n2][n1].

```
for(int i=1;i<=n2;i++){
    for(int j=1;j<=n1;j++){
        if(j<a[i-1])dp[i][j]=dp[i-1][j];
        else dp[i][j]=min(dp[i-1][j],dp[i][j-a[i-1]]+1);
    }
}
```

2. Number

- Initialize dp with 0
- assign x-axis 1 value
- answer is dp[n][k]

```
for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
        if(j<a[i-1])dp[i][j]=dp[i-1][j];
        else dp[i][j]=dp[i-1][j]+dp[i][j-a[i-1]];
    }
}
```

# Coin Game winner

- 


# Gold Mine Problem

- Initialize the dp with 0
- Go right, right_up and right_down.

```
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
```

- Answer will be in goldTable[n-1][0].


# Edit Distance

- Initialize dp with 0.
- Assign x-axis with i and y-axis with i.
- (i-1,j-1) for replace, (i-1,j) for removing, (i,j-1) for insert
- answer is dp[m][n].

```
for(int i=1;i<=m;i++)dp[i][0]=i;
for(int i=1;i<=n;i++)dp[0][i]=i;
for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];
        else dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
    }
}
```


# Egg Dropping 

- Initialize dp with -1.
- Apply binary search from 1 to k.
- 

```
if(k==1 || k==0)return dp[n][k]=k;
if(n==1)return dp[n][k]=k;
```

- Assign x the value when egg brokes and y the value when it didn't.
- store the max value of x and y in res variable. 

```
int l=1,r=k;
while(l<=r){
    int mid=(l+r)/2;
    int x=eggDrop(n-1,mid-1),y=eggDrop(n,k-mid);
    res=min(res,1+max(x,y));
    if(x<y)l=mid+1;
    else r=mid-1;
}
return dp[n][k]=res;
```


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

- Refer file.


# Plaindromic Partitioning

1. 

2. 

3. 

4. 



# Kadane

1. Max Sum
- Store the local and global variable.
- Answer will be in the global.

```
int lo=a[0],go=a[0];
for(int i=1;i<n;i++){
    lo=max(a[i],a[i]+lo);
    go=max(go,lo);
}
```   


2. Max Product
- Store the minimum and maximum number from the array.
- Swap the min and max when negative number occur.

```
int ans=nums[0],maxm=nums[0],minm=nums[0];
for(int i=1;i<nums.size();i++){
    if(nums[i]<0){
        swap(maxm,minm);
    }
    maxm=max(nums[i],nums[i]*maxm);
    minm=min(nums[i],nums[i]*minm);
    ans=max(ans,maxm);
}
```

3. Circular Sub array

- 
```
int kadane(int a[],int n){
    int tmp=a[0],ans=a[0];
    for(int i=1;i<n;i++){
        tmp=max(a[i],tmp+a[i]);
        ans=max(ans,tmp);
    }
    return ans;
}


int ch(int a[],int  n){
    int max1=kadane(a,n);
    int max_wrap=0;
    for(int i=0;i<n;i++){
        max_wrap+=a[i];
        a[i]=-a[i];
    }
    max_wrap=max_wrap+kadane(a,n);
    int ans=max(max_wrap,max1);
    if(ans<=0)return min(max_wrap,max1);
    return ans;
}
```

4. Maximum Sub Rectangle

- Use kadane after updating the res vector.

```
for(int i=0;i<R;i++){
    vector<int>res(C,0);
    for(int j=i;j<R;j++){
        for(int k=0;k<C;k++){
            res[k]+=M[j][k];
        }
        ans=max(ans,kadane(res));
    }
}
```

5. Minimum sum contiguous subarray

- same as max sum

```
int ans=INT_MAX;
int sum=0;
for(int i=0;i<a.size();i++){
    sum=min(a[i],sum+a[i]);
    ans=min(sum,ans);
}
```



# Subsequences

1. Count Palindromic Subsequence:-

- Initialize dp with 0.
- answer is dp[0][n-1].

```
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
```

2. Longest Increasing Subsequence

- Initialize dp with 0.
- 
```
for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
        if(chart[i]>chart[j]&&lis[i]<lis[j]+1)lis[i]=lis[j]+1;
    }
}
```

3. Maximum sum increasing Subsequence

- Initialize dp with the array value.

```    
for(int i=0;i<n;i++)dp[i]=arr[i];

for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
        if(arr[i]>arr[j] && dp[i]<dp[j]+arr[i]){
            dp[i]=dp[j]+arr[i];
            ans=max(ans,dp[i]);   
        }
    }
}
```

4. Length of Longest Increasing Subsequence

- Assign the greater element to the tmp array.
- Size of array is the answer.

```
for(int i=0;i<nums.size();i++){
    if(tmp.empty()||tmp.back()<nums[i])tmp.push_back(nums[i]);
    else *lower_bound(tmp.begin(),tmp.end(),nums[i])=nums[i];
}
```


5. Number of LIS

- Initialize length, count and lis as 1.
- 

```
for(int i = 1; i < n; i++){
    for(int j = 0; j < i; j++){
        if(nums[i] > nums[j]){
            if(len[j] + 1 > len[i]){
                len[i] = len[j] + 1;
                cnt[i] = cnt[j];
            }
            else if(len[j] + 1 == len[i]){
                cnt[i] += cnt[j];
            }
        }
        lis = max(lis, len[i]);
    }
}
int ans = 0;
for(int i = 0; i < n; i++){
    if(len[i] == lis)ans += cnt[i];
}
```


6. Minimum Operations to make the array k increasing

- 

```
for(int i=0;i<k;i++){
    vector<int>tmp;
    for(int j=i;j<arr.size();j+=k){
        if(tmp.empty() || tmp.back()<=arr[j])tmp.push_back(arr[j]);
        else *upper_bound(tmp.begin(),tmp.end(),arr[j])=arr[j];
    }
    longest+=tmp.size();
}
return arr.size()-longest;
```

7. Longest Arithmetic Subsequence

- Store the differenc of the array.
- Maximum of the dp is the answer.
- Result will be ans+1;

```
for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
        int diff=a[i]-a[j];
        mp[i][diff]=mp[j][diff]+1;
        ans=max(ans,mp[i][diff]);
    }
}
```

8. Longest Bitonic Subsequence

- Initialize the dp with 1.
- Store the increasing subsequence from left to right.
- Store the decreasing subsequence from right to left.
- add the above two dp.
- Answer will be the max of all i (dp1[i]+dp2[i])-1.

```
for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
        if(a[i]>a[j]&&(dp1[i]<dp1[j]+1))dp1[i]=dp1[j]+1;
    }
}    
for(int i=n-2;i>=0;i--){
    for(int j=n-1;j>i;j--){
        if(a[i]>a[j]&&(dp2[i]<dp2[j]+1))dp2[i]=dp2[j]+1;
    }
}
```

9. Longest Common Subsequence of String

- Initialize the dp with 0.
- Answer will be dp[n1][n2].

```
for(int i=1;i<=n1;i++){
    for(int j=1;j<=n2;j++){
        if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
}
```

10. Longest Common Subsequence of 3 string 

- Same as LCS of 2 string.

```
for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
        for(int k=0;k<=n1;k++){
            if(i==0||j==0||k==0)dp[i][j][k]=0;
            else if(s1[i-1]==s2[j-1]&&s1[i-1]==s3[k-1])dp[i][j][k]=dp[i-1][j-1][k-1]+1;
            else dp[i][j][k]=max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
        }
    }
}
```

11. Longest Repeating Subsequence

- LCS with s[i-1]==s[j-1] and i!=j condition


12. Longest Palindrome Subsequence

- LCS of string s and reverse string t.


13. 






# Substring

1. Longest Common Substring

- Inititialize dp with 0.

```
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(s[i-1]==t[j-1]){
            dp[i][j]=dp[i-1][j-1]+1;
            maxlen=max(maxlen,dp[i][j]);
            if(maxlen<dp[i][j]){
                maxlen=dp[i][j];
                endindex=i;
            }
        }
    }
}
```





# Larget Divisible Subset

- Initialize dp with 1.
- Iterate through array two times.
- Store the divisible number.

```
for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
        if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
            dp[i]=dp[j]+1;
            pre_node[i]=j;
        }
    }
    if(dp[i]>dp[max_in])max_in=i;
}
```

- 

```
int t=max_in;
while(t>=0){
    ans.push_back(nums[t]);
    t=pre_node[t];
}
```


# Max Square Area

- Initialize dp with 0.

```
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(a[i][j]==1){
            dp[i][j]=1;
            if(i>0&&j>0)
            dp[i][j]+=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        }
        ans=max(ans,dp[i][j]);
    }
}
```

# Larget Rectanle Sub Matrix with sum 0






# Min Path Sum

- prefix sum of x-axis and y-axis.
- 

```
for(int i=1;i<=n;i++)dp[i][0]=dp[i-1][0]+grid[i][0];
for(int j=1;j<=m;j++)dp[0][j]=dp[0][j-1]+grid[0][j];
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        dp[i][j]=min(dp[i][j-1],dp[i-1][j])+grid[i][j];
    }
}
```


# Min Partition Sum

- inclusion and exclusion 

```
int ch(int s[],int n,int s1){
    if(n<0)return abs(sum-2*s1);
    if(dp[n][s1]==-1)dp[n][s1]=ch(s,n-1,s1);
    if(dp[n][s1+s[n]]==-1)dp[n][s1+s[n]]=ch(s,n-1,s1+s[n]);
    return min(dp[n][s1],dp[n][s1+s[n]]);
}

```

# Optimal Game Strategy(Pot of Game)

- 



# Optimal Page Replacement




# Path in Matrix

- Initialize dp with 0.
- assign dp columns value with a columns.
- we can move j-1, j, j+1.

```
for(int i=0;i<n;i++)dp[0][i]=a[0][i];
for(int i=1;i<n;i++){
    for(int j=0;j<n;j++){
        if(j==0){
            dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i-1][j+1]);
        }
        else if(j==n-1){
            dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
        }
        else {
            dp[i][j]=a[i][j]+max(dp[i-1][j],max(dp[i-1][j+1],dp[i-1][j-1]));
        }
    }
}
long long int max1=0;
for(int i=0;i<n;i++)max1=max(max1,dp[n-1][i]);
```


# Matrix Sum 

- Store the prefix sum of 0th row and 0th column.

- 

```
lli tot(lli a[1001][1001],lli n1,lli n2){
    if(sum[n1][n2]!=-1) return sum[n1][n2];
    return sum[n1][n2]=tot(a,n1-1,n2)+tot(a,n1,n2-1)-tot(a,n1-1,n2-1)+a[n1][n2];
}
```


# Maximum Sum pairs with difference less than k

- Initialize dp with 0.
- Final result is in dp[n-1].

```
if(arr[1]-arr[0]<k)dp[1]=arr[1]+arr[0];
else dp[1]=dp[0];
for(int i=2;i<n;i++){
    if((arr[i]-arr[i-1])<k){
        dp[i]=max(dp[i-1],dp[i-2]+arr[i]+arr[i-1]);
    }
    else {
        dp[i]=dp[i-1];
    }
}

```

# Mobile Numeric Keypad 





# Regular Expression

- Initialize dp as false.
- Make dp[0][0] as true.
- Make columns as below

```
for(int i=1;i<=m;i++){
    if(p[i-1]=='*')dp[0][i]=dp[0][i-2];
}
```

-  

```
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(p[j-1]=='.' || s[i-1]==p[j-1]){
            dp[i][j]=dp[i-1][j-1];
        }
        else if(p[j-1]=='*'){
            dp[i][j]=dp[i][j-2];
            if(p[j-2]=='.' || p[j-2]==s[i-1]){
                dp[i][j]=dp[i][j]|dp[i-1][j];
            }
        }
        else dp[i][j]=false;
    }
}
```


# Rod Cutting Problem

- include when i is equal and greater then a[i].

```
if(i-a[2]>=0)dp[i]=max(dp[i],dp[i-a[2]]+1);
```


# Word Wrap

- Initialize dp with 0.
- 

```
for(int i=n-2;i>=0;i--){
    currlen=-1;
    dp[i]=INT_MAX;
    for(int j=i;j<n;j++){
        currlen+=(nums[j]+1);
        if(currlen>k)
            break;
        if(j==n-1)
            cost=0;
        else
            cost=(k-currlen)*(k-currlen)+dp[j+1];
            
        dp[i]=min(dp[i],cost);
    }
}
```

# Word Break

- Use unordered set to store all the strings.
- Initialize dp with -1.

```
int dp[305];

bool find(string s,int in,unordered_set<string>&arr){
    if(s.length()==in){
        return 1;
    }
    
    if(dp[in]!=-1)return dp[in];
    
    for(int i=1;i<=s.length()-in;i++){
        if(arr.find(s.substr(in,i))!=arr.end() && find(s,i+in,arr))return dp[in]=1;
    }
    return dp[in]=0;
}
```

# nCr

- Initialize the dp with 0 and size k+1.
- assign

```
c[0]=1;
for(lli i=1;i<=n;i++){
    for(lli j=min(i,k);j>0;j--){
        c[j]=c[j]+c[j-1];
    }
}
```

- answer will be in c[k].



1. No of path in Matrix






# S D K edges

