class Solution
{
    public:
        int maxProfit(vector<int> &v)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            int mnSoFar = INT_MAX, maxProfit = 0, n = v.size();
            for (int i = 0; i < n; i++)
            {
                mnSoFar = min(mnSoFar, v[i]);
                maxProfit = max(maxProfit, v[i] - mnSoFar);
            }
            return maxProfit;
        }
};