class Solution
{
    public:
        vector<vector < int>> generateMatrix(int n)
        {
            int top = 0, bottom = n - 1, left = 0, right = n - 1, check = 1;
            vector<vector < int>> ans;
            for (int i = 0; i < n; i++)
            {
                vector<int> temp;
                for (int j = 0; j < n; j++)
                {
                    temp.push_back(0);
                }
                ans.push_back(temp);
            }
            while (top < n and bottom >= 0 and left < n and right >= 0)
            {
                for (int i = left; i <= right; i++)
                {
                    ans[top][i] = check++;
                }
                top++;
                for (int i = top; i <= bottom; i++)
                {
                    ans[i][right] = check++;
                }
                right--;
                for (int i = right; i >= left; i--)
                {
                    ans[bottom][i] = check++;
                }
                bottom--;
                for (int i = bottom; i >= top; i--)
                {
                    ans[i][left] = check++;
                }
                left++;
            }

            return ans;
        }
};