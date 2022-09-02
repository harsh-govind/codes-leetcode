class Solution
{
    public:
        vector<int> findDisappearedNumbers(vector<int> &nums)
        {
            int n = nums.size();
            unordered_map<int, int> s;
            for (int i = 1; i <= n; i++)
            {
                s[i] = 0;
            }

            for (auto &val: nums)
            {
                s[val]++;
            }
            vector<int> ans;
            for (auto &val: s)
            {
                if (val.second == 0)
                {
                    ans.push_back(val.first);
                }
            }

            return ans;
        }
};