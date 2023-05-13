class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());

            vector<vector < int>> ans;

            for (int i = 0; i < nums.size(); i++)
            {
                if (i == 0 or(i > 0 and nums[i - 1] != nums[i]))
                {
                    int req = -nums[i], l = i + 1, h = nums.size() - 1;

                    while (l < h)
                    {
                        if (nums[l] + nums[h] == req)
                        {
                            vector<int> temp;
                            temp.push_back(nums[i]);
                            temp.push_back(nums[l]);
                            temp.push_back(nums[h]);
                            ans.push_back(temp);
                            while (l < h and nums[l] == nums[l + 1]) l++;
                            while (l < h and nums[h] == nums[h - 1]) h--;

                            l++;
                            h--;
                        }
                        else if (nums[l] + nums[h] < req)
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