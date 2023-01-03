class Solution
{
    public:
        bool isMonotonic(vector<int> &nums)
        {
            vector<int> inc = nums, dec = nums;
            sort(inc.begin(), inc.end());
            sort(dec.begin(), dec.end(), greater<int> ());

            return inc == nums or dec == nums;
        }
};