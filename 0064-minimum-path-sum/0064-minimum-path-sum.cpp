class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>prev(m,0);

for(int i=0;i<n;i++){
    vector<int>curr(m,0);
    for(int j=0;j<m;j++){
        if(i==0&&j==0){
            curr[j]=grid[0][0];
        }
        else{
 int up=1e8,left=1e8;
    if(i>=1){
 up=grid[i][j]+prev[j];
    }
    if(j>=1){
        left=grid[i][j]+curr[j-1];
    }
            curr[j]=min(left,up);
        }

    }
    prev=curr;
    }
      return prev[m-1];
    }
};