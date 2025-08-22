//https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#



class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int row=-1,i=0,j=m-1;
	    while(i<n&&j>=0){
	        if(arr[i][j]==1){
	            j--;
	            row=i;
	        }
	        else i++;
	    }
	    return row;
	}

};
