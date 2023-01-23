class Solution
{
    public:
        vector<int> numberOfPairs(vector<int> &nums)
        {
            int pairs = 0, leftover = 0;
            unordered_map<int, int> mp;

            for (auto &val: nums)
            {
                mp[val]++;
            }

            for (auto &val: mp)
            {
                pairs += val.second / 2;
                leftover += val.second % 2;
            }

            return {
                pairs,
                leftover
            };
        }
};