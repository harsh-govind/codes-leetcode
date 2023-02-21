class Solution
{
    public:
        int singleNonDuplicate(vector<int> &nums)
        {
            unordered_map<int, int> mp;
            for (auto &val: nums)
            {
                mp[val]++;
            }

            for (auto &val: mp)
            {
                if (val.second == 1)
                {
                    return val.first;
                }
            }
            return 69;
        }
};