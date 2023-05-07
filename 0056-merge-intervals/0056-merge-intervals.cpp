class Solution
{
    public:
        vector<vector < int>> merge(vector<vector < int>> &arr)
        {
            sort(arr.begin(), arr.end());
            int n = arr.size(), i = 0;
            vector<vector < int>> ans;
            while (i < n)
            {
                int low = arr[i][0], high = arr[i][1];
                i++;
                while (i < n and arr[i][0] >= low and arr[i][0] <= high)
                {
                    high = max(high, arr[i][1]);
                    i++;
                }

                vector<int> temp;
                temp.push_back(low);
                temp.push_back(high);
                ans.push_back(temp);
            }

            return ans;
        }
};