//https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1#


    int countBitsFlip(int a, int b){
        
        // Your logic here
        int ans=0;
        int flipbits=a^b;
        while(flipbits!=0){
            flipbits=flipbits&(flipbits-1);
            ans++;
        }
        return ans;
    }
