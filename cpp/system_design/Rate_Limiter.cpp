
/*

Low Level Design of Rate Limitor using sliding Window Protocol.
Assuming Limiting Rate as 3 Requests/sec.

*/

#include<bits/stdc++.h>
#include <windows.h>
using namespace std;
using namespace std::chrono;

uint64_t currTimeInMS() {
	uint64_t x =  system_clock::now().time_since_epoch().count();
	x/=1000;
	x/=1000;
	return x;
}

int request_id = 1;

class SlidingWindow
{
	public:
	queue<uint64_t> slidingWindow;
	int timeWindowInSeconds;
	int bucketCapacity;
	SlidingWindow(){}
	SlidingWindow(int timeWindowInSeconds, int bucketCapacity){
		this->timeWindowInSeconds = timeWindowInSeconds;
		this->bucketCapacity = bucketCapacity;
		cout<<" Size of queue is "<<slidingWindow.size()<<endl;
	}
	bool grantAccess(){
		cout<<endl<<"Request no : " <<request_id<<endl;
		request_id++;
		uint64_t currTime = currTimeInMS();
		//cout<<" Time of Request "<<currTime<<endl;
		checkAndUpdateQueue(currTime);
		if(slidingWindow.size()<bucketCapacity){
			slidingWindow.push(currTime);
			//cout<<currTime<<endl;
			cout<<" Added to queue successfully \n Size of queue is "<<slidingWindow.size()<<endl;
			return true;
		} else {
			cout<< " Queue is Full, can't accomodate "<<endl;
			return false;
		}
	}

	void checkAndUpdateQueue(uint64_t currTime){
		//cout<<" Checking Queue"<<endl;
		if(slidingWindow.empty()){
			cout<<" Returning as queue is empty() \n"; 
			return;
		}
		uint64_t calculatedTime = (currTime - slidingWindow.front());
		cout<<" diff "<<calculatedTime<<endl;
		calculatedTime = calculatedTime/1000;
		// cout<<"windowSize "<<timeWindowInSeconds<<endl;
		while(calculatedTime>=timeWindowInSeconds){
			cout<<"  Emptying the queue as the current request has come after elapsing the time window\n"<<endl;
			slidingWindow.pop();
			if(slidingWindow.empty()) break;
			calculatedTime = (currTime - slidingWindow.front())/1000;
		}
	}
};

class UserBucket{
public:
	int id;
	SlidingWindow q;
	unordered_map<int,SlidingWindow> bucket;
	UserBucket(int id){
		this->id = id;
		SlidingWindow p(1,3);
		bucket[id] = p;
	}
	void access(){
		if(bucket[id].grantAccess()){
			cout<<" ACCESS GRANTED "<<endl;
		} else cout<<" ACCESS DENIED "<<endl;
	}
};

int main (){


	UserBucket b(1234);
	b.access();
	b.access();
	Sleep(500);
	b.access();
	Sleep(500);
	b.access();
	b.access();
	b.access();
	Sleep(1000);
	b.access();
	b.access();
	b.access();


	// UserBucket c(4321);
	// c.access();
	// c.access();
	// c.access();
	// b.access();
	// c.access();
	// Sleep(1000);
	// b.access();
	// c.access();

	// SlidingWindow s(1,10);

	// for (int i = 0; i < 20; ++i)
	// {
	// 	/* code */
	// 	s.grantAccess();
	// }

	// s.grantAccess();
	// Sleep(100);

	// s.grantAccess();
	// Sleep(100);

	// s.grantAccess();
	// Sleep(100);

	// s.grantAccess();
	// Sleep(1000);
	// s.grantAccess();
	// s.grantAccess();
	// s.grantAccess();
	// s.grantAccess();

  	return 0;
}
