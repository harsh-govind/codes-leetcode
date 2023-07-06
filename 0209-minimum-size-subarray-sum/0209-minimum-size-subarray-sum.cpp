class Solution
{
    public:
        int minSubArrayLen(int target, vector<int> &nums)
        {
            int ans = INT_MAX, l = 0, h = 0, sum = 0;

            while (h < nums.size())
            {
                sum += nums[h];
                if (sum >= target)
                {
                     while (sum >= target)
                    {
                        sum -= nums[l];
                        l++;
                    }

                    ans = min(ans, h - l + 2);
                }
                h++;
            }

            return ans == INT_MAX ? 0 : ans;
        }
};