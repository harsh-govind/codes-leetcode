class Solution
{
    public:
        vector<int> removeDuplicate(vector<int> &nums)
        {
            vector<int> ans;
            set<int> s;
            for (auto &v: nums)
            {
                s.insert(v);
            }
            for (auto &v: s)
            {
                ans.push_back(v);
            }
            return ans;
        }
    int longestConsecutive(vector<int> &k)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> nums = removeDuplicate(k);
        int maxCount = 0, currentCount = 0;
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] + 1 == nums[i])
            {
                if (currentCount == 0)
                {
                    currentCount++;
                }
                currentCount++;
            }
            else
            {
                maxCount = max(currentCount, maxCount);
                currentCount = 0;
            }
        }
        maxCount = max(currentCount, maxCount);
        if (maxCount == 0)
            maxCount++;
        return maxCount;
    }
};