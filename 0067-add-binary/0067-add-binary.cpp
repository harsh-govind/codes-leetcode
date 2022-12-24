class Solution
{
    public:
        string addBinary(string a, string b)
        {
            int m = a.size(), n = b.size();
            int j = m - 1, k = n - 1;
            string ans = "";
            char carry = '0';
            for (int i = min(m, n) - 1; i >= 0; i--)
            {
                int temp = (carry - '0') + (a[j--] - '0') + (b[k--] - '0');

                if (temp == 0)
                {
                    ans += '0';
                    carry = '0';
                }
                else if (temp == 1)
                {
                    ans += '1';
                    carry = '0';
                }
                else if (temp == 2)
                {
                    ans += '0';
                    carry = '1';
                }
                else if (temp == 3)
                {
                    ans += '1';
                    carry = '1';
                }
            }

            int i = abs(m - n) - 1;
            string rem;
            if (m > n)
            {
                rem = a;
            }
            else if (n > m)
            {
                rem = b;
            }
            if (carry == '1')
            {
                while (i >= 0)
                {
                    int temp = (rem[i] - '0') + (carry - '0');

                    if (temp == 0)
                    {
                        ans += '0';
                        carry = '0';
                    }
                    else if (temp == 1)
                    {
                        ans += '1';
                        carry = '0';
                    }
                    else if (temp == 2)
                    {
                        ans += '0';
                        carry = '1';
                    }
                    else if (temp == 3)
                    {
                        ans += '1';
                        carry = '1';
                    }
                    i--;
                }
            }
            else
            {
                while (i >= 0)
                {
                    ans += rem[i--];
                }
            }

            if (carry == '1')
            {
                ans += '1';
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
};