class Solution
{
    public:
        int maxProfit(vector<int> &v)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            int mn = INT_MAX, mx = 0, n = v.size();
            for (int i = 0; i < n; i++)
            {
                if (mn > v[i])
                {
                    mn = v[i];
                }
                else if (mx < (v[i] - mn))
                {
                    mx = v[i] - mn;
                }
            }
            return mx;
        }
};