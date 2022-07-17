class Solution
{
    public:
        vector<vector < int>> merge(vector<vector < int>> &a)
        {
            int n = a.size(), i, j, second;
            sort(a.begin(), a.end());
            vector<vector < int>> ans;
            for (i = 0; i < n;)
            {
                j = i + 1;
                vector<int> temp;
                temp.push_back(a[i][0]);
                second = a[i][1];
                while (j < n and a[j][0] >= a[i][0] and a[j][0] <= second)
                {
                    second = max(second, a[j][1]);
                    j++;
                }
                i = j;
                temp.push_back(second);
                ans.push_back(temp);
            }
            return ans;
        }
};