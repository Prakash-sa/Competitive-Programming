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






void median(double arr[], int n) 
{ 
    priority_queue<double> s; 
    priority_queue<double,vector<double>,greater<double> > g; 
    double med = arr[0]; 
    s.push(arr[0]); 
    cout << med << endl;   
    for (int i=1; i < n; i++) 
    { 
        double x = arr[i]; 
        // case1(left side heap has more elements) 
        if (s.size() > g.size()) 
        { 
            if (x < med) 
            { 
                g.push(s.top()); 
                s.pop(); 
                s.push(x); 
            } 
            else
                g.push(x); 
  
            med = (s.top() + g.top())/2.0; 
        } 
        // case2(both heaps are balanced) 
        else if (s.size()==g.size()) 
        { 
            if (x < med) 
            { 
                s.push(x); 
                med = (double)s.top(); 
            } 
            else
            { 
                g.push(x); 
                med = (double)g.top(); 
            } 
        } 
        // case3(right side heap has more elements) 
        else
        { 
            if (x > med) 
            { 
                s.push(g.top()); 
                g.pop(); 
                g.push(x); 
            } 
            else
                s.push(x); 
  
            med = (s.top() + g.top())/2.0; 
        } 
        cout << (int)med << endl; 
    } 
} 
 
int main()
{
   boost;
   int t=1;
  // cin>>t;
   while(t--){
       int n;
       cin>>n;
       double a[n];
       for(int i=0;i<n;i++)cin>>a[i];
       if(n==1){
           cout<<a[0];
       }
       else 
        median(a,n);
   }
   return 0;
}