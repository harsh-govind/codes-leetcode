class Solution
{
    public:
        bool isSubsetSum(vector<int> arr, int sum)
        {
            int n = arr.size(), i, j;
            bool t[n + 1][sum + 1];
            for (i = 0; i < n + 1; i++)
            {
                for (j = 0; j < sum + 1; j++)
                {
                    if (i == 0)
                    {
                        t[i][j] = false;
                    }
                    if (j == 0)
                    {
                        t[i][j] = true;
                    }
                }
            }

            for (i = 1; i < n + 1; i++)
            {
                for (j = 1; j < sum + 1; j++)
                {
                    if (arr[i - 1] <= j)
                    {
                        t[i][j] = t[i - 1][j - arr[i - 1]] or t[i - 1][j];
                    }
                    else
                    {
                        t[i][j] = t[i - 1][j];
                    }
                }
            }
            return t[n][sum];
        }

    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
        {
            return false;
        }

        return isSubsetSum(nums, sum / 2);
    }
};