class Solution
{
    public:
        vector<vector < int>> matrixReshape(vector<vector < int>> &mat, int r, int c)
        {
            if(r*c != mat.size()*mat[0].size())
            {
                return mat;
            }
            vector<int> temp;
            for (auto &i: mat)
            {
                for (auto &val: i)
                {
                    temp.push_back(val);
                }
            }

            int k = 0;

            vector<vector < int>> ans;

            for (int i = 0; i < r; i++)
            {
                vector<int> l;
                for (int j = 0; j < c; j++)
                {
                    l.push_back(temp[k++]);
                }
                ans.push_back(l);
            }
            return ans;
        }
};