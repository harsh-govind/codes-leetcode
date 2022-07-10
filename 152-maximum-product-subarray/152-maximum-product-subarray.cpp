class Solution
{
    public:
        int maxProduct(vector<int> &nums)
        {
            int mx, mn, ans;
            mx=mn=ans=nums[0];
            
            for(int i=1;i<nums.size(); i++)
            {
                int val = nums[i];
                if(val<0)
                {
                    swap(mx, mn);
                }
                mx=max(val, mx*val);
                mn=min(val, mn*val);
                ans=max(mx, ans);
            }
            return ans;
        }
};