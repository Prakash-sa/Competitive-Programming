//https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/



class Solution {
    
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int k) {
        sort(tiles.begin(),tiles.end());
        int n = tiles.size();
        vector<int> pre(n,0);
        pre[0]=tiles[0][1]-tiles[0][0]+1;       
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + tiles[i][1]-tiles[i][0]+1;
        }
        
        vector<int> tile;
        for(auto &i : tiles)tile.push_back(i[0]);
        
        int ans = 0;
        for(int i=0;i<n;i++){
            // binary search to find the index where the carpet ends.
            auto it = lower_bound(tile.begin(),tile.end(),k+tiles[i][0]); 
            if(it!=tile.end() and (*it)>k+tiles[i][0])
                --it;
            
            // adding the elements which are completely covered by carpet. 
            int t1=it-tile.begin()-1>=0 ? pre[it-tile.begin()-1] : 0;
            int t2=i-1>=0 ? pre[i-1] : 0;
            int temp = t1-t2;
            
            // adding the last element which may or may not completely be covered by the carpet.
            if(it!=tile.end() and (k+tiles[i][0])>=(*it)){
                t1=k+tiles[i][0]-(*it);
                t2=it-tile.begin()-1>=0 ? pre[it-tile.begin()-1] : 0;
                temp+=min(t1,pre[it-tile.begin()]-t2);
            
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};
