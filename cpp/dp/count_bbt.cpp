//https://www.geeksforgeeks.org/count-balanced-binary-trees-height-h/




class Solution {
  public:
    long long int countBT(int h) { 
        // code here
        long long int mod=1e9+7;
        long long int a=1,b=1,c;
        for(int i=2;i<=h;i++){
            c=b*(b+2*a);
            c=c%mod;
            a=b,b=c;
        }
        return c;
    }
};

