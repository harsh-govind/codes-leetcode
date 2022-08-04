class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<=i;j++)
            {
                temp.push_back(1);
            }
            ans.push_back(temp);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<i;j++)
            {
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
                
            }
        }
        
       
        return ans;
    }
};