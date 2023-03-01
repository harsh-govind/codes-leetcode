class Solution
{
    public:
        vector<int> sortArray(vector<int> &nums)
        {
            multiset<int> s;

            for (auto &v: nums)
            {
                s.insert(v);
            }

            int i = 0;
            for (auto &v: s)
            {
                nums[i++] = v;
            }
            return nums;
        }
};