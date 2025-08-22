//https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450



void interLeaveQueue(queue < int > & q) {
    // Write your code here.
	int n=q.size()/2;
	stack<int>st;
	for(int i=0;i<n;i++){
		st.push(q.front());
		q.pop();
	}
	for(int i=0;i<n;i++){
		q.push(st.top());
		st.pop();
	}
	for(int i=0;i<n;i++){
		q.push(q.front());
		q.pop();
	}
	for(int i=0;i<n;i++){
		st.push(q.front());
		q.pop();
	}
	while(!st.empty()){
		q.push(st.top());
		st.pop();
		q.push(q.front());
		q.pop();
	}
}
