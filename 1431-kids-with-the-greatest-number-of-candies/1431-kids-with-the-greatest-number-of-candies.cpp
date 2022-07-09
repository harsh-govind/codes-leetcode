class Solution
{
    public:
        vector<bool> kidsWithCandies(vector<int> &v, int e)
        {
            int mx = *max_element(v.begin(), v.end());
            vector<bool> ans;
            for (auto &val: v)
            {
                if (val + e >= mx)
                {
                    ans.push_back(true);
                }
                else
                {
                    ans.push_back(false);
                }
            }
            return ans;
        }
};