class Solution
{
    public:
        int maxProduct(vector<int> &nums)
        {
            int b = INT_MIN, a = INT_MIN, temp, n = nums.size();
            for (int i = 0; i < n; i++)
            {
                if (nums[i] > a)
                {
                    a = max(a, nums[i]);
                    temp = i;
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (nums[i] > b and i != temp)
                {
                    b = max(b, nums[i]);
                }
            }
            return ((a - 1) *(b - 1));
        }
};