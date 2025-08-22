//https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1#



class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue<int>q;
	    for(int i=0;i<n;i++)q.push(arr[i]);
	    vector<int>ans;
	    while(k--){
	        ans.push_back(q.top());
	        q.pop();
	    }
	    return ans;
	}

};
