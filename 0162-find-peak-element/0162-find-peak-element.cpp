class Solution
{
    public:
        int findPeakElement(vector<int> &nums)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                bool left = true, right = true;

                for (int l = 0; l <= i - 1; l++)
                {
                    if (nums[l] > nums[i])
                    {
                        left = false;
                        break;
                    }
                }

                for (int r = i + 1; r < nums.size(); r++)
                {
                    if (nums[r] > nums[i])
                    {
                        right = false;
                        break;
                    }
                }

                if (left and right) return i;
            }

            return -1;
        }
};