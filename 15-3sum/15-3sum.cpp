class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            vector<vector < int>> ans;
            sort(nums.begin(), nums.end());
            int n = nums.size();
            for (int i = 0; i < n - 2; i++)
            {
                if (i == 0 || (i > 0 && nums[i - 1] != nums[i]))
                {
                    int l = i + 1, h = n - 1, sum = 0 - nums[i];

                    while (l < h)
                    {
                        if (nums[l] + nums[h] == sum)
                        {
                            vector<int> temp;
                            temp.push_back(nums[l]);
                            temp.push_back(nums[h]);
                            temp.push_back(nums[i]);
                            ans.push_back(temp);
                            while (l < h and nums[l] == nums[l + 1])
                            {
                                l++;
                            }
                            while (l < h and nums[h] == nums[h - 1])
                            {
                                h--;
                            }

                            l++;
                            h--;
                        }
                        else if (nums[l] + nums[h] < sum)
                        {
                            l++;
                        }
                        else
                        {
                            h--;
                        }
                    }
                }
            }
            return ans;
        }
};