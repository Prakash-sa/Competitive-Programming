//https://leetcode.com/problems/design-underground-system/




class UndergroundSystem {
    
    unordered_map<int,pair<string,int>>checkInMap;
    unordered_map<string,pair<int,int>>route;
    
public:
    UndergroundSystem() {
        checkInMap.clear();
        route.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id]={stationName,t};    
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkin=checkInMap[id];
        checkInMap.erase(id);
        string tmp=checkin.first+"_"+stationName;
        route[tmp].first+=t-checkin.second;
        route[tmp].second+=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double ans;
        string s=startStation+"_"+endStation;
        ans=(double)route[s].first/route[s].second;
        return ans;
    }
};
