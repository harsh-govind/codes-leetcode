class Solution
{
    public:
        void solve(int idx, vector<int> &candidates, int key, vector<int> &temp, vector< vector< int>> &ans)
        {
            if (key == 0)
            {
                ans.push_back(temp);
                return;
            }

            for (int i = idx; i < candidates.size(); i++)
            {
                if (i > idx and candidates[i] == candidates[i - 1])
                {
                    continue;
                }
                if (key < candidates[i])
                {
                    break;
                }

                temp.push_back(candidates[i]);
                solve(i + 1, candidates, key - candidates[i], temp, ans);
                temp.pop_back();
            }
        }
    vector<vector < int>> combinationSum2(vector<int> &candidates, int key)
    {
        vector<vector < int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(0, candidates, key, temp, ans);
        return ans;
    }
};