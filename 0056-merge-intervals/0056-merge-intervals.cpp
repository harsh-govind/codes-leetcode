class Solution
{
    public:
        vector<vector < int>> merge(vector<vector < int>> &arr)
        {
            sort(arr.begin(), arr.end());
            int n = arr.size(), i = 0;
            vector<vector < int>> ans;
            stack<pair<int, int>> stk;
            for (int i = 0; i < n; i++)
            {
                if (stk.empty())
                {
                    stk.push({ arr[i][0],
                        arr[i][1] });
                }
                else
                {
                    pair<int, int> temp = stk.top();
                    stk.pop();
                    if (arr[i][0] >= temp.first and arr[i][0] <= temp.second)
                    {
                        stk.push({ temp.first,
                            max(temp.second, arr[i][1]) });
                    }
                    else
                    {
                        stk.push(temp);
                        stk.push({ arr[i][0],
                            arr[i][1] });
                    }
                }
            }

            while (!stk.empty())
            {
                vector<int> temp;
                temp.push_back(stk.top().first);
                temp.push_back(stk.top().second);
                ans.push_back(temp);
                stk.pop();
            }

            return ans;
        }
};