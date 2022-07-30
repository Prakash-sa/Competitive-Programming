//https://leetcode.com/problems/count-integers-in-intervals/

/*
Given an empty set of intervals, implement a data structure that can:

    Add an interval to the set of intervals.
    Count the number of integers that are present in at least one interval.

Implement the CountIntervals class:

    CountIntervals() Initializes the object with an empty set of intervals.
    void add(int left, int right) Adds the interval [left, right] to the set of intervals.
    int count() Returns the number of integers that are present in at least one interval.

Note that an interval [left, right] denotes all the integers x where left <= x <= right.

 

Example 1:

Input
["CountIntervals", "add", "add", "count", "add", "count"]
[[], [2, 3], [7, 10], [], [5, 8], []]
Output
[null, null, null, 6, null, 8]

*/


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

