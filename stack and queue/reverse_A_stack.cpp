//https://practice.geeksforgeeks.org/problems/reverse-a-stack/1/#









class Solution{
    stack<int>ans;
    
    void insert_at_bottom(int x){
        if(ans.size()==0){
            ans.push(x);   
            return;
        }
        int tmp=ans.top();
        ans.pop();
        insert_at_bottom(x);
        ans.push(tmp);
    }
    
    void reverse(){
        if(ans.size()>0){
            int x=ans.top();
            ans.pop();
            reverse();
            insert_at_bottom(x);
        }
    }
    
public:
    stack<int> Reverse(stack<int> St){
        ans=St;
        reverse();
        return ans;
    }
};
