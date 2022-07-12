#include<bits/stdc++.h>
using namespace std;


class Meeting;

typedef vector<Meeting>Calendar;

class Room{
    public:
    Room(string);
    bool book(int,int);
    const string& getName() const;


    private:
    string name;
    Calendar calendar;
};

class Meeting{
    public:
    Meeting(int,int,Room);
    int getEnd()const;
    int getStart() const;

    private:

    int start,end;
    Room room;
};

class Scheduler{

    vector<Room>rooms;
    public:
    Scheduler(vector<Room>rooms);
    string book(int,int);

};

Room::Room(string name){
    this->name=name;
}

const string& Room::getName() const{
    return name;
}

bool Room::book(int start,int end){
    for(Meeting m:calendar){
        if(m.getStart()<end && start<m.getEnd())return false;
    }

    Meeting meeting(start,end,*this);
    calendar.push_back(meeting);
    return true;
}

Meeting::Meeting(int start,int end,Room room):room(room){
    this->start=start;
    this->end=end;
}

int Meeting::getEnd() const{
    return end;
}

int Meeting::getStart() const{
    return start;
}

Scheduler::Scheduler(vector<Room>rooms){
    this->rooms=rooms;
}

string Scheduler::book(int start,int end){
    for(Room &room:rooms){
        bool flag=room.book(start,end);
        if(flag==true)return room.getName();
    }
    return "No rooms are available.";
}

int main(){

    Room room1("Atlas");
    Room room2("Nexus");
    Room room3("HolyCow");

    vector<Room>roomVec;
    roomVec.push_back(room1);
    roomVec.push_back(room2);
    roomVec.push_back(room3);

    Scheduler scheduler(roomVec);

    cout<<scheduler.book(2,5)<<endl;
    cout<<scheduler.book(5,8)<<endl;
    cout<<scheduler.book(4,8)<<endl;
    cout<<scheduler.book(3,6)<<endl;
    cout<<scheduler.book(7,8)<<endl;


    return 0;
}