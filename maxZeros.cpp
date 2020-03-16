/*
For n = 9, the output should be
maxZeros(n) = 2.
9 = 10012 = 1003 = 214...
If you'll try all other bases, you'll see that
the maximum possible number of zeros in 
these representations is 2, thus the answer is k = 2.*/

int maxZeros(int n) {
    int ma=0,k=0;
    for(int i=2;i<=n;i++){
        int p=n;
        int m=0;
        while(p){
            if(p%i==0)m++;
            p=p/i;
        }
        if(ma<m){
            ma=m;
            k=i;
        }
    }
    return k;

}
