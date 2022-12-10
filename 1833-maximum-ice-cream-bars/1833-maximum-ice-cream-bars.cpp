class Solution
{
    public:
        int maxIceCream(vector<int> &costs, int coins)
        {
            sort(costs.begin(), costs.end());
            int i = 0, n = costs.size(), ans = 0;
            if (costs[0] > coins)
            {
                return 0;
            }
            while (i < n)
            {
                if (coins - costs[i] < 0)
                {
                    break;
                }
                ans++;
                coins -= costs[i];

                i++;
            }

            return ans;
        }
};