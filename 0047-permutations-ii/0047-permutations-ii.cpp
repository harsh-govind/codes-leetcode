class Solution
{
    private:
        void solve(vector<int> &nums, int index, vector<vector< int >> &ans, set< vector< int>> &s)
        {
            if (index == nums.size())
            {
                if (s.find(nums) == s.end())
                {
                    ans.push_back(nums);
                }
                s.insert(nums);
                return;
            }

            for (int i = index; i < nums.size(); i++)
            {
                swap(nums[i], nums[index]);
                solve(nums, index + 1, ans, s);
                swap(nums[i], nums[index]);
            }
        }
    public:
        vector<vector < int>> permuteUnique(vector<int> &nums)
        {
            vector<vector < int>> ans;
            set<vector < int>> s;
            solve(nums, 0, ans, s);
            return ans;
        }
};