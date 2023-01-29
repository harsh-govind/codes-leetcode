class Solution
{
    public:
        vector<int> majorityElement(vector<int> &nums)
        {
            unordered_map<int, int> m;

            for (auto &v: nums)
            {
                m[v]++;
            }

            vector<int> ans;
            int n = nums.size();

            for (auto &v: m)
            {
                if (v.second > floor(n / 3))
                {
                    ans.push_back(v.first);
                }
            }

            return ans;
        }
};