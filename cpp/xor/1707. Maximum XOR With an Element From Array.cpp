//https://leetcode.com/problems/maximum-xor-with-an-element-from-array/



class Solution {
    
    struct Node{
        Node* zero_bit=nullptr;
        Node* one_bit=nullptr;
    };
    
    Node* root=new Node();
    
    void insert(const int& num ){
        Node* ptr=root;
        for(int i=31;i>=0;i--){
            if((num>>i)&1){
                if(!ptr->one_bit)ptr->one_bit=new Node();
                ptr=ptr->one_bit;
            }
            else {
                if(!ptr->zero_bit)ptr->zero_bit=new Node();
                ptr=ptr->zero_bit;
            }
        }
    }
    
    int getMaxXOR(const int& num){
        if(root->zero_bit==nullptr && root->one_bit == nullptr)return -1;
        
        Node* ptr=root;
        int tmp=0;
        
        for(int i=31;i>=0;i--){
            if((num>>i)&1){
                if(ptr->zero_bit){
                    tmp+=pow(2,i);
                    ptr=ptr->zero_bit;
                }
                else {
                    ptr=ptr->one_bit;
                }
            }
            else {
                if(ptr->one_bit){
                    tmp+=pow(2,i);
                    ptr=ptr->one_bit;
                }
                else {
                    ptr=ptr->zero_bit;
                }
            }
        }
        return tmp;
    }
    
    
    
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>>q;
        for(int i=0;i<queries.size();i++){
            auto v=queries[i];
            q.push_back({v[1],v[0],i});
        }
        sort(q.begin(),q.end());
        sort(nums.begin(),nums.end());
        int j=0;
        vector<int>res(queries.size());
        for(auto &p:q){
            int x=p[1];
            int threshold=p[0];
            while(j<nums.size()&& nums[j]<=threshold){
                insert(nums[j]);
                j++;
            }
            res[p[2]]=getMaxXOR(x);
        }
        return res;
    }
};