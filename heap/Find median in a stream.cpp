//https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1#






class Solution
{
    priority_queue<int,vector<int>,greater<int>>minHeap;
    priority_queue<int>maxHeap;
    
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(maxHeap.empty() || maxHeap.top()>=x)
        maxHeap.push(x);
        else minHeap.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(maxHeap.size()<minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        int n=minHeap.size()+maxHeap.size();
        if(n%2==0){
            return (double)(minHeap.top()+maxHeap.top())/2;
        }
        return maxHeap.top();
    }
};

