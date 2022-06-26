//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxi=0,mask=0;
        /*The maxResult is a record of the largest XOR we got so far. if it's 11100 at i = 2, it means 
        before we reach the last two bits, 11100 is the biggest XOR we have, and we're going to explore
        whether we can get another two '1's and put them into maxResult
        
        This is a greedy part, since we're looking for the largest XOR, we start 
        from the very begining, aka, the 31st postition of bits. */
        for(int i=31;i>=0;i--){
              //The mask will grow like  100..000 , 110..000, 111..000,  then 1111...111
            //for each iteration, we only care about the left parts
            mask=mask|(1<<i);
            set<int>s;
            for(auto ni:nums){
/*                we only care about the left parts, for example, if i = 2, then we have
                {1100, 1000, 0100, 0000} from {1110, 1011, 0111, 0010}*/
                s.insert(mask&ni);
            }

            // if i = 1 and before this iteration, the maxResult we have now is 1100, 
            // my wish is the maxResult will grow to 1110, so I will try to find a candidate
            // which can give me the greedyTry;
            int greedy=maxi|(1<<i);
            for(auto si:s){
                //This is the most tricky part, coming from a fact that if a ^ b = c, then a ^ c = b;
                // now we have the 'c', which is greedyTry, and we have the 'a', which is leftPartOfNum
                // If we hope the formula a ^ b = c to be valid, then we need the b, 
                // and to get b, we need a ^ c, if a ^ c exisited in our set, then we're good to go
                int anotherNum=si^greedy;
                if(s.find(anotherNum)!=s.end()){
                    maxi=greedy;
                    break;
                }
            }
        }
        return maxi;
    }
};