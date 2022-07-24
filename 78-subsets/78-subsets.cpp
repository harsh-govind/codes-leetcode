class Solution
{
    public:
    vector<vector < int>> ans;
    void generateSubsets(vector<int> &subset, int i, vector<int> &nums)
    {
        if (i == nums.size())
        {
            ans.push_back(subset);
            return;
        }
       	// skipping i
        generateSubsets(subset, i + 1, nums);

        subset.push_back(nums[i]);
        generateSubsets(subset, i + 1, nums);
        subset.pop_back();
    }
    vector<vector < int>> subsets(vector<int> &nums) {
        vector<int> empty;
        generateSubsets(empty, 0, nums);
        return ans;
    }
};