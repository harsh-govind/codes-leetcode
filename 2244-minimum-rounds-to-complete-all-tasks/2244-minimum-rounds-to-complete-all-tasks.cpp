class Solution
{
    public:
        int minimumRounds(vector<int> &tasks)
        {
            unordered_map<int, int> mp;

            for (auto &val: tasks)
            {
                mp[val]++;
            }
            int ans = 0;
            for (auto &val: mp)
            {
                if (val.second < 2)
                {
                    return -1;
                }

                int num = val.second;

                ans += num/3;
                num%=3;
                ans+=num/2;
                ans+=num%2;
            };
            return ans;
        }
};