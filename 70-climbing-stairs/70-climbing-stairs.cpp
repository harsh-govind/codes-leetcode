class Solution
{
    public:
        int t[50];
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            t[n] = n;
            return n;
        }
        if (t[n - 2] == 0)
        {
            t[n - 2] = climbStairs(n - 2);
        }
        if (t[n - 1] == 0)
        {
            t[n - 1] = climbStairs(n - 1);
        }
        return t[n - 2] + t[n - 1];
    }
};