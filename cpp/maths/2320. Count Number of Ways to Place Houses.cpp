//https://leetcode.com/problems/count-number-of-ways-to-place-houses/

class Solution {
public:
    int countHousePlacements(int n) {
        long long house=1,space=1,total,mod=1e9+7;
        total=house+space;
        for(int i=2;i<=n;i++){
            house=space;
            space=total;
            total=(house+space)%mod;
        }
        return (1ll)*(total*total)%mod;
    }
};