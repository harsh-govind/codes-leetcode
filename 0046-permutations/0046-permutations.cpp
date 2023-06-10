class Solution
{
    private:
        void solve(vector<int> &nums, vector<int> &current, vector< vector< int >> &ans, unordered_set< int > &s)
        {
            if (current.size() == nums.size())
            {
                ans.push_back(current);
                return;
            }

            for (int i = 0; i < nums.size(); i++)
            {
                if (s.find(nums[i]) == s.end())
                {
                    s.insert(nums[i]);
                    current.push_back(nums[i]);
                    solve(nums, current, ans, s);
                    current.pop_back();
                    s.erase(nums[i]);
                }
            }
        }
    public:
        vector<vector < int>> permute(vector<int> &nums)
        {
            unordered_set<int> s;
            vector<vector < int>> ans;
            vector<int> current;
            solve(nums, current, ans, s);
            return ans;
        }
};