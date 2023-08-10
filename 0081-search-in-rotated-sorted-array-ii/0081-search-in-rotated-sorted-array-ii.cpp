class Solution
{
    public:
        bool search(vector<int> &nums, int x)
        {
            return find(nums.begin(), nums.end(), x) != nums.end();
        }
};