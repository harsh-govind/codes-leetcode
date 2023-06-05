class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        int n=nums.size();
        long long sum=0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; i++)
        {
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n-2; j++)
            {
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                int left=j+1, right=n-1;
                while(left<right)
                {
                    sum=nums[i]+nums[j];
                    sum+=nums[left];
                    sum+=nums[right];
                    if(sum==target)
                    {
                        ans.insert({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                    }
                    else if(sum>target)
                    {
                        right--;
                    }
                    else
                    {
                        left++;
                    }
                }
            }
        }
        vector<vector<int>> finalAns(ans.begin(), ans.end());
        return finalAns;
    }
};