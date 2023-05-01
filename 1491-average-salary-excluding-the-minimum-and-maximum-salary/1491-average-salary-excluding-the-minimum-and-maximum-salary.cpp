class Solution
{
    public:
        double average(vector<int> &salary)
        {
            int mx = INT_MIN, mn = INT_MAX;
            double sum = 0;

            for (auto &val: salary)
            {
                sum += val;
                mn = min(mn, val);
                mx = max(mx, val);
            }

            return (sum - (mn + mx)) / (salary.size() - 2);
        }
};