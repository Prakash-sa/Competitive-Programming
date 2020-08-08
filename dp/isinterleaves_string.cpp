//-----------------isinterleaves string-----------------------//
int lcs(string A,string B,string C){
    int n=A.size();
    int m=B.size();
    int IL[n+1][m+1];
    if((m+n)!=C.size())return false;
    memset(IL, 0, sizeof(IL));
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
    
    return IL[n][m];
}


