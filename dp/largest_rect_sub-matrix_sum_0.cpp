//https://practice.geeksforgeeks.org/problems/largest-rectangular-sub-matrix-whose-sum-is-0/1/#




class Solution{
    bool sum_k(int arr[], int& start, int& end, int n, int k) {
       unordered_map<int, int> map;
       int sum = 0, maximum_length = 0;
       for (int i = 0; i < n; i++) {
          sum += arr[i];
          if (sum == k) {
             maximum_length = i + 1;
             start = 0;
             end = i;
          }
          if (map.find(sum) == map.end())
             map[sum] = i;
          if (map.find(sum - k) != map.end()) {
             if (maximum_length < (i - map[sum - k])) {
                maximum_length = i - map[sum - k];
                start = map[sum - k] + 1;
                end = i;
             }
          }
       }
       return (maximum_length != 0);
    }
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> mat){
      //Code Here
       int row = mat.size();
       int col = mat[0].size();
       int temp[row], area;
       bool sum;
       int up, down;
       vector<int> final = {0,0,0,0};
       int maxArea = INT_MIN;
       for (int left = 0; left < col; left++) {
          memset(temp, 0, sizeof(temp));
          // har baar cumulative sum bhejenge sum_k mein
          for (int right = left; right < col; right++) {
             for (int i = 0; i < row; i++)
                temp[i] += mat[i][right];
             sum = sum_k(temp, up, down, row, 0);
             area = (down - up + 1) * (right - left + 1);
             if (sum && maxArea < area) {
                final[0] = up;
                final[1] = down;
                final[2] = left;
                final[3] = right;
                maxArea = area;
             }
          }
       }
        
        vector<vector<int>> out(final[1]-final[0]+1, vector<int>(final[3]-final[2]+1, -1));
        
        if(final[0]==0 &&final[1]==0 &&final[2]==0 &&final[3]==0 && mat[0][0]!=0){
            return out;
        }
        int l=0, m=0;
        for(int i=final[0]; i<=final[1]; i++)
        {
            for(int j=final[2]; j<=final[3]; j++)
            {
                out[l][m++] = mat[i][j];
            }
            m=0;
            l++;
        }
        //if(glo==INT_MIN) return -1;
        return out;
  }
};




//https://www.geeksforgeeks.org/largest-area-rectangular-sub-matrix-equal-number-1s-0s/


0->-1
1->1
