class Solution
{
    public:
        unsigned int countSetBit(unsigned int n)
        {
            unsigned int ans = 0;
            while (n)
            {
                ans += n &1;
                n >>= 1;
            }
            return ans;
        }
    vector<int> countBits(int n)
    {
        vector<int> ans;

        for (int i = 0; i <= n; i++)
        {
            ans.push_back(countSetBit(i));
        }
        return ans;
    }
};