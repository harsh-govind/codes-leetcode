class Solution
{
    public:
        int threeSumClosest(vector<int> &nums, int target)
        {
            sort(nums.begin(), nums.end());
            int temp = INT_MAX, ans = INT_MAX;
            int n = nums.size();

            for (int i = 0; i < n; i++)
            {
                int curr = nums[i];

                int start = i + 1, end = n - 1;

                while (start < end)
                {

                    if (nums[start] + curr + nums[end] == target)
                    {
                        return nums[start] + curr + nums[end];
                    }
                    else if (abs(nums[start] + curr + nums[end] - target) < temp)
                    {
                        temp = abs(nums[start] + curr + nums[end] - target);
                        ans = nums[start] + curr + nums[end];
                    }
                    if (nums[start] + curr + nums[end] > target)
                    {
                        end--;
                    }
                    else
                    {
                        start++;
                    }
                }
            }

            return ans;
        }
};