//https://practice.geeksforgeeks.org/problems/sort-a-stack/1#


void insert(stack<int> &s,int e){
    if(s.empty() || s.top()<e){
        s.push(e);
        return;
    }
    int t=s.top();
    s.pop();
    insert(s,e);
    s.push(t);
}
void SortedStack :: sort()
{
   //Your code here
   if(s.empty())return;
    int t=s.top();
    s.pop();
    sort();
    insert(s,t);
}

