class Solution
{
    public:
        Solution()
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        }
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        while (n > 0)
        {
            ans += n &1;
            n = n >> 1;
        }
        return ans;
    }
};