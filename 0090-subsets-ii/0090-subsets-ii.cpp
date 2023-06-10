class Solution {
public:
    void solve(vector<int> &nums,vector<vector<int>> &ans, vector<int> current, int i)
    {
        if(i==nums.size())
        {
            ans.push_back(current);
            return;
        }
         
        //include
        current.push_back(nums[i]);
        solve(nums, ans, current, i+1);
        //uncomment the line below if you want to send current as reference (backtracking)
        current.pop_back();
        
        
        //exclude
        while(i+1<nums.size() and nums[i]==nums[i+1]) i++;
        solve(nums, ans, current, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(nums.begin(), nums.end());
        solve(nums, ans, current, 0);
        return ans;
    }
};