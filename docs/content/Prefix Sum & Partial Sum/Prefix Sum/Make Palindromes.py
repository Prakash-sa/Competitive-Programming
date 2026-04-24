

'''
You are given a string **s** consisting of lowercase alphabets and must answer **q** queries. 
Each query is of the form **(l, r, k)**, where **(l, r)** represents the substring boundaries of **s**. 
You are allowed to rearrange the characters in this substring in any order. Additionally, you can perform at most **k substitutions**, 
where each substitution allows you to replace any character in the substring with another character of your choice. 
For each query, determine whether the substring can be converted into a **palindrome** using these operations. 
After processing all queries, output a string **ans** of length **q**, where **ansᵢ = '1'** if the substring in the **i-th** query can be converted into a palindrome, otherwise **ansᵢ = '0'**.
'''




t=int(input())
for _ in range(t):
    s=input().strip()
    freq_str=[[0]*26 for _ in range(len(s))]
    for i in range(len(s)):
        if i>0:
            freq_str[i]=freq_str[i-1].copy()
        freq_str[i][ord(s[i])-ord('a')]+=1
    q=int(input())
    ans=''
    for _ in range(q):
        l,r,k=list(map(int,input().split()))
        r-=1
        l-=1
        odd_count=0
        for j in range(26):
            cnt=freq_str[r][j]-(freq_str[l-1][j] if l>0 else 0)
            if cnt &1:
                odd_count+=1
        length=r-l+1
        if odd_count<=2*k+(length&1):
            ans+='1'
        else:
            ans+='0'
    print(ans)


'''
Overall per test case: O((n + q) * 26), which is effectively O(n + q) because 26 is constant.
Across all test cases (given sum(n) + sum(q) ≤ 2 * 10^6):
Total time: O(26 * 2*10^6) ⇒ ~ O(2*10^6) operations scale.

Space complexity
Prefix frequency table: if you store pref of size (n+1) x 26 ⇒ O(n * 26)
Answer string/list: O(q)
'''
