class Solution
{
    public:
        vector<int> shuffle(vector<int> &nums, int n)
        {
            std::ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
            vector<int> v;
            int j = (n);
            for (int i = 0; i < n; i++)
            {
                v.push_back(nums[i]);
                v.push_back(nums[j++]);
            }
            return v;
        }
};