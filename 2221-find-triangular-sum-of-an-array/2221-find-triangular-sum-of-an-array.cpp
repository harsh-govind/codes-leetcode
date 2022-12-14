class Solution
{
    public:
        int triangularSum(vector<int> &nums)
        {

            vector<int> store = nums;
            int n = nums.size();
            for (int i = 1; i < n; i++)
            {
                vector<int> k;
                for (int j = 0; j < n - i; j++)
                {
                    k.push_back((store[j] + store[j + 1]) % 10);
                }
                store = k;
            }
            return store[0];
        }
};