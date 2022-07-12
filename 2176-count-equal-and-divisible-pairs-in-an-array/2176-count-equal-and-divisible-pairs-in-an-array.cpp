class Solution
{
    public:
        int countPairs(vector<int> &nums, int k)
        {
            int ans = 0;
            int i = 0, j = nums.size() - 1;
            while (i < j)
            {
                if (nums[i] == nums[j] and ((i *j) % k == 0))
                {
                    ans++;
                }
                if (j == i+1)
                {
                    i++;
                    j = nums.size() - 1;
                }
                else
                {
                    j--;
                }
            }
            return ans;
        }
};