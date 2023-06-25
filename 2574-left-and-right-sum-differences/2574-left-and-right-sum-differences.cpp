class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans;
        int leftSum=0, rightSum=accumulate(nums.begin(), nums.end(), 0);
        
        for(int i=0; i<nums.size();i++)
        {
            rightSum-=nums[i];
            ans.push_back(abs(rightSum-leftSum));
            leftSum+=nums[i];
        }
        return ans;
    }
};