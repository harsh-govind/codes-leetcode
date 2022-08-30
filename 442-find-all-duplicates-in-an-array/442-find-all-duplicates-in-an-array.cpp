class Solution
{
    public:
        vector<int> findDuplicates(vector<int> &nums)
        {
            vector<int> ans;
            unordered_set<int> s;

            for (auto &val: nums)
            {
                if (s.find(val) != s.end())
                {
                    ans.push_back(val);
                }
                else
                {
                    s.insert(val);
                }
            }
            return ans;
        }
};