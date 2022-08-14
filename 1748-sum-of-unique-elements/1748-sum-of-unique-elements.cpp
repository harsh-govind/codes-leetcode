class Solution
{
    public:
        int sumOfUnique(vector<int> &nums)
        {
            unordered_map<int, int> m;
            for (auto &val: nums)
            {
                m[val]++;
            }

            int ans = 0;
            for (auto &val: m)
            {
                if (val.second == 1)
                {
                    ans += val.first;
                }
            }
            return ans;
        }
};