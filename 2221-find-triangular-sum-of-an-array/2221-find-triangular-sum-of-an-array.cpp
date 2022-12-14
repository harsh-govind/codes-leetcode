class Solution
{
    public:
        int triangularSum(vector<int> &nums)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            vector<int> store = nums;
            int n = nums.size();
            for (int i = 1; i < n; i++)
            {
                vector<int> k;
                for (int j = 0; j < n - i; j++)
                {
                    k.push_back((nums[j] + nums[j + 1]) % 10);
                }
                nums = k;
            }
            return nums[0];
        }
};