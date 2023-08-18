class Solution {
public:
    vector<int> merge(vector<int> &nums, int mid, int high)
    {
        vector<int> ans;
        int i=mid-1, j=mid;
        while(i>=0 and j<high)
        {
            if(nums[i]<nums[j])
            {
                ans.push_back(nums[i--]);
            }
            else if(nums[i]>nums[j])
            {
                ans.push_back(nums[j++]);
            }
            else
            {
                ans.push_back(nums[i--]);
                ans.push_back(nums[j++]);
            }
        }
        
        while(i>=0)
        {
            ans.push_back(nums[i--]);
        }
        
        while(j<high)
        {
            ans.push_back(nums[j++]);
        }
        
        return ans;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        int changePoint=0;
        int n=nums.size();
        for(int i=1; i<n; i++)
        {
            if(nums[i-1]<0 and nums[i]>=0)
            {
                changePoint=i;
                break;
            }
        }
        bool allNeg=true;
        for(auto &v:nums)
        {
            if(v>=0) allNeg=false;
            v*=v;
        }
        
        if(allNeg)
        {
            reverse(nums.begin(), nums.end());
            return nums;
        }

        return merge(nums, changePoint, n);
    }
};