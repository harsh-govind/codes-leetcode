class Solution
{
    public:
        vector<int> arrayChange(vector<int> &nums, vector<vector< int>> &operations)
        {
            unordered_map<int, int> m;
            for (int i = 0; i < nums.size(); i++)
            {
                m[nums[i]] = i;
            }

            for (int i = 0; i < operations.size(); i++)
            {
                int location = m[operations[i][0]];
                nums[location] = operations[i][1];
                m[nums[location]] = m[operations[i][0]];
            }

            return nums;
        }
};