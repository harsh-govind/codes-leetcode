class Solution
{
    public:
        bool solve(vector<int> &nums, int l, int h, int x)
        {
            while (l <= h)
            {
                int m = (l + h) / 2;
                if (nums[m] == x)
                {
                    return true;
                }
                else if (nums[l] < nums[m])
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
                else if (nums[m] < nums[l])
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
                else
                {
                    l++;
                }
            }

            return false;
        }
    bool search(vector<int> &nums, int x)
    {
        return solve(nums, 0, nums.size() - 1, x);
    }
};