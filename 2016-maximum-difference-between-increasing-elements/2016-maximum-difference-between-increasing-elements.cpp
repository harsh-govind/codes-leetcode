class Solution
{
    public:
        int maximumDifference(vector<int> &prices)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            int minSoFar = prices[0], maxProfit = 0, currProfit = 0;

            for (auto &v: prices)
            {
                minSoFar = min(minSoFar, v);
                currProfit = v - minSoFar;
                maxProfit = max(currProfit, maxProfit);
            }
            if (maxProfit < 0 or maxProfit == 0)
            {
                return -1;
            }
            return maxProfit;
        }
};