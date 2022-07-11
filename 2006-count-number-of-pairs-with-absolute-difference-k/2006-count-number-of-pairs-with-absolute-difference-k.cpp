class Solution
{
    public:
        int countKDifference(vector<int> &nums, int k)
        {
            int ans = 0, n = nums.size();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (nums[i] - nums[j] == k or nums[i] - nums[j] == (-k))
                        ans++;
                }
            }
            return ans;
        }
};