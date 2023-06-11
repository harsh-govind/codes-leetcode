class Solution
{
    public:
        void solve(int i, int k, vector<int> &current, vector<vector< int>> &ans, int n)
        {
            if (current.size() == k)
            {
                ans.push_back(current);
                return;
            }

            if (i - 1 < n)
            {
               	//include
                current.push_back(i);
                solve(i + 1, k, current, ans, n);
                current.pop_back();

               	//exclude
                solve(i + 1, k, current, ans, n);
            }
        }
    vector<vector < int>> combine(int n, int k)
    {
        vector<int> current;
        vector<vector < int>> ans;
        solve(1, k, current, ans, n);
        return ans;
    }
};