//https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1#











int countRev (string s)
{
    // your code here
    stack<char>st;
    int start=0;
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='{'){
            st.push('{');
            start++;
        }
        else{
            if(start>0)start--;
            else start++,ans++; 
        }
    }
    if(start%2==1)return -1;
    return ans+start/2;
}
