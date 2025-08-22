//https://practice.geeksforgeeks.org/problems/queue-reversal/1








void solve(queue<int>&q){
    if(q.empty())return;
    int x=q.front();
    q.pop();
    solve(q);
    q.push(x);
}

//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    // add code here.
    solve(q);
    return q;
}
