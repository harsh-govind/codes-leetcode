class Solution
{
    private:
        void solve(vector<int> &nums, int index, vector<vector< int >> &ans)
        {
            if (index == nums.size())
            {
                ans.push_back(nums);
                return;
            }

            unordered_set<int> s;
            for (int i = index; i < nums.size(); i++)
            {
                if(s.find(nums[i])!=s.end()) continue;
                
                s.insert(nums[i]);
                swap(nums[i], nums[index]);
                solve(nums, index + 1, ans);
                swap(nums[i], nums[index]);
            }
        }
    public:
        vector<vector < int>> permuteUnique(vector<int> &nums)
        {
            vector<vector < int>> ans;
            solve(nums, 0, ans);
            return ans;
        }
};