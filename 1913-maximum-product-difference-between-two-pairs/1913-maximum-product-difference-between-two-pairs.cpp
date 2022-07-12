class Solution
{
    public:
        int maxProductDifference(vector<int> &nums)
        {
            bool flag = true;
            int a, b, c, d, bc, cc;
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
                if (i > 0)
                    if (nums[i] != nums[i - 1])
                    {
                        flag = false;
                    }
            }
            if (flag)
                return 0;
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