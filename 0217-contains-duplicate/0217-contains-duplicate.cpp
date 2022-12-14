class Solution
{
    public:
        bool containsDuplicate(vector<int> &nums)
        {
            unordered_set<int> m;
            for (auto &val: nums)
            {
                if (m.find(val) == m.end())
                {
                    m.insert(val);
                }
                else
                {
                    return true;
                }
            }
            return false;
        }
};