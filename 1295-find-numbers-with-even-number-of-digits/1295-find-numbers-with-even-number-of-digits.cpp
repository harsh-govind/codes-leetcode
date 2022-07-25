class Solution
{
    public:
        int digitCount(int n)
        {
            int ans;
            while (n > 0)
            {
                ans++;
                n /= 10;
            }
            return ans;
        }
    int findNumbers(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (digitCount(nums[i]) % 2 == 0)
                ans++;
        }
        return ans;
    }
};