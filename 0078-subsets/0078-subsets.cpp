class Solution {
public:
    void solve(vector<int> &nums,vector<vector<int>> &ans, vector<int> &current, int i)
    {
        if(i==nums.size())
        {
            ans.push_back(current);
            return;
        }
        
        //exclude
        solve(nums, ans, current, i+1);
        
        //include
        current.push_back(nums[i]);
        solve(nums, ans, current, i+1);
        
        //uncomment the line below if you want to send current as reference
        current.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(nums, ans, current, 0);
        return ans;
    }
};