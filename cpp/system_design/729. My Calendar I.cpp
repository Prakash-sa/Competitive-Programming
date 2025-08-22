//https://leetcode.com/problems/my-calendar-i/

/*
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.
A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).
The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.
Implement the MyCalendar class:
MyCalendar() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
 

Example 1:

Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
Output
[null, true, false, true]
*/


class MyCalendar {
    map<int,int>mp;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it=mp.lower_bound(start);
        if(it!=mp.end() && (*it).first<end)return false;
        if(it!=mp.begin() && (*--it).second>start)return false;
        mp[start]=end;
        return true;
    }
};



//https://leetcode.com/problems/my-calendar-ii/

/*
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.
A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).
The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.
Implement the MyCalendarTwo class:
MyCalendarTwo() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.

 

Example 1:

Input
["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
Output
[null, true, true, true, false, true, true]
*/

class MyCalendar {
    map<int,int>mp;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it=mp.lower_bound(start);
        if(it!=mp.end() && (*it).first<end)return false;
        if(it!=mp.begin() && (*--it).second>start)return false;
        mp[start]=end;
        return true;
    }
};


//https://leetcode.com/problems/my-calendar-iii/
/*
A k-booking happens when k events have some non-empty intersection (i.e., there is some time that is common to all k events.)
You are given some events [start, end), after each given event, return an integer k representing the maximum k-booking between all the previous events.
Implement the MyCalendarThree class:
MyCalendarThree() Initializes the object.
int book(int start, int end) Returns an integer k representing the largest integer such that there exists a k-booking in the calendar.
 

Example 1:

Input
["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
Output
[null, 1, 1, 2, 3, 3, 3]
*/

class MyCalendarThree {
    map<int,int>mp;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int booked=0,ans=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            booked+=it->second;
            ans=max(ans,booked);
        }
        return ans;
    }
};
