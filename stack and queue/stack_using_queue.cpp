queue<int>q1,q2;
void QueueStack :: push(int x)
{
        // Your Code
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
        // Your Code
        if(q1.empty())return -1;
        int ans=q1.front();
        q1.pop();
        return ans;
}