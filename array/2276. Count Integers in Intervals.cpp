//https://leetcode.com/problems/count-integers-in-intervals/



class CountIntervals {
    int cnt;
    set<pair<int,int>>s;
public:
    CountIntervals() {
        s.clear();
        cnt=0;
    }
    
    void add(int left, int right) {
        auto it=s.lower_bound({left,right});
        if(it!=s.end()){
            auto [pleft,pright]=*it;
            if(pleft<=right){
                cnt-=pright-pleft+1;
                s.erase(it);
                add(left,max(right,pright));
                return;
            }
        }
        if(it!=s.begin()){
            auto [pleft,pright]=*(--it);
            if(pright>=left){
                cnt-=pright-pleft+1;
                s.erase(it);
                add(pleft,max(right,pright));
                return;
            }
        }
        cnt+=right-left+1;
        s.insert({left,right});
    }
    
    int count() {
        return cnt;
    }
};

