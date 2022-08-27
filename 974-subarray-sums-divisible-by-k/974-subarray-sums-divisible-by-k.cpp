class Solution
{
    public:
        int subarraysDivByK(vector<int> &nums, int k)
        {
            int sum = 0, ans = 0;
            unordered_map<int, int> rem;
            rem[0]++;
            for (auto &val: nums)
            {
                sum += val;
                int temp = sum % k;
                if (temp < 0)
                {
                    temp += k;
                }
                if (rem.find(temp) != rem.end())
                {
                    ans += rem[temp];
                }

                rem[temp]++;
            }

            return ans;
        }
};