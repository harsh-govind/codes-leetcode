class Solution
{
    public:
        int findGCD(vector<int> &nums)
        {
            int mn = INT_MAX, mx = INT_MIN;
            for (auto &val: nums)
            {
                mn = min(mn, val);
                mx = max(mx, val);
            }
            return __gcd(mn, mx);
        }
};