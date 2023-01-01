class Solution
{
    public:
        int missingNumber(vector<int> &v)
        {
            int n = v.size();
            n = (n *(n + 1)) / 2;
            int sum = accumulate(v.begin(), v.end(), 0);
            return n - sum;
        }
};