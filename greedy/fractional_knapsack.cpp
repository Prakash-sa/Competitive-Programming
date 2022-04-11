//https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1










struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    static bool cmp(Item a,Item b){
        double a1=(double)a.value/a.weight;
        double b1=(double)b.value/b.weight;
        if(a1>b1)return true;
        return false;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        double ans=0;
        for(int i=0;i<n;i++){
            if(W>arr[i].weight){
                ans+=arr[i].value;
                W-=arr[i].weight;
            }
            else {
                ans+=((double)arr[i].value)*(double)W/((double)arr[i].weight);
                break;
            }
        }
        return ans;
    }
        
};

