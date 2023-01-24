class Solution
{
    public:
        vector<int> searchRange(vector<int> &nums, int x)
        {
            int n = nums.size();

            vector<int> ans;

            int m, l = 0, h = n - 1, k;

            if (find(nums.begin(), nums.end(), x) == nums.end())
            {
                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
            }

            while (l <= h)
            {
                m = l + (h - l) / 2;

                if (nums[m] == x)
                {
                    k = m;
                    h = m - 1;
                }
                else if (nums[m] > x)
                {
                    h = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }

            ans.push_back(k);
            l = 0;
            h = n - 1;
            while (l <= h)
            {
                m = l + (h - l) / 2;

                if (nums[m] == x)
                {
                    k = m;
                    l = m + 1;
                }
                else if (nums[m] > x)
                {
                    h = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }

            ans.push_back(k);

            return ans;
        }
};