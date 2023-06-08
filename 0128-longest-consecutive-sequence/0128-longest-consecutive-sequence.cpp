class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            if (nums.size() == 0 or nums.size() == 1) return nums.size();
            unordered_set<int> m;
            int curr = 0, maxx = 0;
            for (auto &val: nums)
            {
                m.insert(val);
            }
            int ans = INT_MIN;
            for (auto &val: nums)
            {
                if (m.find(val - 1) == m.end())
                {
                    int currVal = val, temp = 1;
                    while (m.find(currVal + 1) != m.end())
                    {
                        temp++;
                        currVal += 1;
                    }

                    ans = max(temp, ans);
                }
            }
            return ans;
        }
};