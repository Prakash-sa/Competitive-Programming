void StackQueue ::push(int x)
{
    s1.push(x);
}
/*The method pop which return the element poped out of the queue*/
int StackQueue ::pop()
{
    if (s2.empty())
    {
        if (s1.empty())
            return -1;
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int k = s2.top();
        s2.pop();
        return k;
    }
    else
    {
        int k = s2.top();
        s2.pop();
        return k;
    }
}

//

class MyQueue
{
    stack<int> st1, st2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        st2.push(x);
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
    }

    int pop()
    {
        int k = st2.top();
        st2.pop();
        return k;
    }

    int peek()
    {
        return st2.top();
    }

    bool empty()
    {
        return st2.empty() == true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */