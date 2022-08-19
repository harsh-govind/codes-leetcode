class Solution
{
    public:
        bool divideArray(vector<int> &nums)
        {
            int ans = true;

            unordered_map<int, int> m;

            for (auto &val: nums)
            {
                m[val]++;
            }

            for (auto &val: m)
            {
                if (val.second % 2 != 0)
                {
                    ans = false;
                    break;
                }
            }

            return ans;
        }
};