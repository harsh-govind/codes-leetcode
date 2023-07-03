class Solution
{
    public:
        bool increasingTriplet(vector<int> &nums)
        {
            int mid = INT_MAX, low = INT_MAX;
            for (auto &val: nums)
            {
                if (mid < val)
                {
                    return true;
                }
                else if (val < mid and val > low)
                {
                    mid = val;
                }
                else if (val < low)
                {
                    low = val;
                }
            }
            return false;
        }
};