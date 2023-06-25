class Solution
{
    public:
        int maxOperations(vector<int> &nums, int k)
        {
            unordered_map<int, int> s;
            int ans = 0;
            for (auto &val: nums)
            {
                if (s.find(k - val) != s.end() and s[k-val]>0)
                {
                    ans++;
                    s[k - val]--;
                }
                else
                {
                    s[val]++;
                }
            }
            return ans;
        }
};