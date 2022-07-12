class Solution
{
    public:
        int maxProductDifference(vector<int> &nums)
        {
            bool flag = true;
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] != nums[i - 1])
                {
                    flag = false;
                }
            }
            if (flag)
                return 0;
            long long a, b, c, d, bc, cc;
            a = b = INT_MIN;
            c = d = INT_MAX;
            for (int i = 0; i < nums.size(); i++)
            {
                int val = nums[i];
                if (val > b)
                {
                    b = val;
                    bc = i;
                }

                if (val < c)
                {
                    c = val;
                    cc = i;
                }
            }
            for (int i = 0; i < nums.size(); i++)
            {
                int val = nums[i];
                if (val > a and i != bc)
                {
                    a = val;
                }
                if (val < d and i != cc)
                {
                    d = val;
                }
            }
            cout << a << " " << b << " " << c << " " << d << endl;
            return (a *b) - (c *d);
        }
};