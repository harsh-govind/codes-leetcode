class Solution
{
    public:
        int findMin(vector<int> &nums)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            return* min_element(nums.begin(), nums.end());
        }
};