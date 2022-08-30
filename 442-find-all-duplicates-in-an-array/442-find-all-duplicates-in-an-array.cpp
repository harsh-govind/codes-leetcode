class Solution
{
    public:
        vector<int> findDuplicates(vector<int> &nums)
        {
            vector<int> ans;
            for (int i = 0; i < nums.size(); i++)
            {
                int location = abs(nums[i]) - 1;

                if (nums[location] < 0)
                {
                    ans.push_back(abs(nums[i]));
                }
                else
                {
                    nums[location] = nums[location] *(-1);
                }
            }
            return ans;
        }
};