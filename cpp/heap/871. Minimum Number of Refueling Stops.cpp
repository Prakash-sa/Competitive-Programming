//https://leetcode.com/problems/minimum-number-of-refueling-stops/


/*
A car travels from a starting position to a destination which is target miles east of the starting position.
There are gas stations along the way. The gas stations are represented as an array stations where stations[i] = [positioni, fueli] 
indicates that the ith gas station is positioni miles east of the starting position and has fueli liters of gas.
The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. 
It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, 
transferring all the gas from the station into the car.
Return the minimum number of refueling stops the car must make in order to reach its destination. 
If it cannot reach the destination, return -1.
Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. 
If the car reaches the destination with 0 fuel left, it is still considered to have arrived.


Example 1:

Input: target = 1, startFuel = 1, stations = []
Output: 0
Explanation: We can reach the target without refueling.

Example 2:

Input: target = 100, startFuel = 1, stations = [[10,100]]
Output: -1
Explanation: We can not reach the target (or even the first gas station).
*/


class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& s) {
        int i=0,res;
        priority_queue<int>pq;
        for(res=0;startFuel<target;res++){
            while(i<s.size() && s[i][0]<=startFuel)pq.push(s[i++][1]);
            
            if(pq.empty())return -1;
            startFuel+=pq.top();
            pq.pop();
        }
        return res;
    }
};