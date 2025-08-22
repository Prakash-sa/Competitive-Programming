int solve(string A) {
    string rev = A;
    reverse(A.begin(),A.end());
    int n = rev.size();
    
    int lcp[n],len=0,i=1;
    lcp[0] = 0;
    while ( i<n ){
        if ( A[i]==A[len] ){
            lcp[i] = len;
            len++;
            i++;
        } else {
            if ( len ) len = lcp[len-1];
            else {
                lcp[i] = len;
                i++;
            }
        }
    }
    
    i = 0; 
    len = 0;
    while ( i<n ){
        if ( A[i]==rev[len] ){
            len++;
            i++;
        } else {
            if ( len ) len = lcp[len-1];
            else i++;
        }
    }
    return n-len;
    
}
