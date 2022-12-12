class Solution
{
    public:
        void findAns(int i, int target, vector<int> &temp, vector<vector< int >> &ans, vector< int > &arr)
        {
            if (i == arr.size())
            {
                if (target == 0)
                {
                    ans.push_back(temp);
                }
                return;
            }

            if (arr[i] <= target)
            {
                temp.push_back(arr[i]);
                findAns(i, target - arr[i], temp, ans, arr);
                temp.pop_back();
            }

            findAns(i + 1, target , temp, ans, arr);
        }
    vector<vector < int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector < int>> ans;
        vector<int> temp;
        findAns(0, target, temp, ans, candidates);
        return ans;
    }
};