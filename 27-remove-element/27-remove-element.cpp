class Solution {
public:
    int removeElement(vector<int> &nums, int k)
{
    int ans = 0;
    for (auto &val : nums)
    {
        if (val == k)
        {
            ans++;
        }
    }
            for (int l = 0; l < ans; l++)

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == k)
        {
            for (int j = i; j < nums.size()-1; j++)
            {
                nums[j] = nums[j + 1];
            }
        }
    }
    return nums.size()-ans;
}
};