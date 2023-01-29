class Solution
{
    public:
        int mostFrequentEven(vector<int> &nums)
        {
            std::ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
            map<int, int> m;

            for (auto &v: nums)
            {
                if (v % 2 == 0)
                {
                    m[v]++;
                }
            }

            if (m.size() == 0)
            {
                return -1;
            }

            int ans = INT_MIN, k = INT_MIN;

            for (auto &val: m)
            {
                if (val.second > k)
                {
                    k = val.second;
                    ans = val.first;
                }
            }
            return ans;
        }
};