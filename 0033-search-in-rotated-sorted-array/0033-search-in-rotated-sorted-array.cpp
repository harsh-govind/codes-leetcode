class Solution
{
    public:
        int search(vector<int> &nums, int x)
        {
            int l = 0, h = nums.size() - 1;
            while (l <= h)
            {
                int m = (l + h) / 2;
                if (nums[m] == x)
                {
                    return m;
                }
                else if (nums[l] <= nums[m])
                {
                    if (x >= nums[l] and x <= nums[m])
                    {
                        h = m - 1;
                    }
                    else
                    {
                        l = m + 1;
                    }
                }
                else
                {
                    if (x >= nums[m] and x <= nums[h])
                    {
                        l = m + 1;
                    }
                    else
                    {
                        h = m - 1;
                    }
                }
            }

            return -1;
        }
};