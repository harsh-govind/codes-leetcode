class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r=matrix.size(), c=matrix[0].size();
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<=i;j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<(c/2);j++)
            {
                swap(matrix[i][j], matrix[i][c-j-1]);
            }
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};