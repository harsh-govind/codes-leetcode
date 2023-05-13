class Solution
{
    public:
        vector<int> rowAndMaximumOnes(vector<vector < int>> &mat)
        {
            vector<int> ans;
            int row, max1 = INT_MIN;
            for (int i = 0; i < mat.size(); i++)
            {
                int temp = 0;
                for (int j = 0; j < mat[0].size(); j++)
                {
                    if (mat[i][j] == 1) temp++;
                }
                if (temp > max1)
                {
                    max1 = temp;
                    row = i;
                }
            }

            ans.push_back(row);
            ans.push_back(max1);
            return ans;
        }
};