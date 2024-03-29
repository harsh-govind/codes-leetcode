class Solution
{
    public:
        Solution()
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        }
    bool isPowerOfThree(int n)
    {
        if (n < 0)
            return false;
        set < long long > s;
        long long check = 1;
        s.insert(1);
        for (int i = 0; i <= 18; i++)
        {
            s.insert(check *= 3);
        }
        return s.find(n) != s.end();
    }
};