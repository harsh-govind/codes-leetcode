class Solution
{
    public:
        int maxSubArray(vector<int> &nums)
        {
            bool isAllNegative = true;
            int maxElement = INT_MIN;
            for (auto &val: nums)
            {
                if (val >= 0)
                {
                    isAllNegative = false;
                }
                maxElement = max(maxElement, val);
            }
            if (isAllNegative)
            {
                return maxElement;
            }

            int currentMax = 0, ansMax = 0;

            for (auto &val: nums)
            {
                currentMax += val;
                ansMax = max(ansMax, currentMax);
                if (currentMax < 0)
                {
                    currentMax = 0;
                }
            }

            return ansMax;
        }
};