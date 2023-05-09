class Solution
{
    public:
        int majorityElement(vector<int> &nums)
        {
            int ans = 0, count = 0;
            for (auto &val: nums)
            {
                if (count == 0)
                {
                    ans = val;
                }
                if (ans == val)
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }

            return ans;
        }
};