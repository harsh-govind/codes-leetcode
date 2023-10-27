class Solution
{
    public:
        int solve(string s, int i, int j)
        {
            while (i >= 0 and j < s.size() and s[i] == s[j])
            {
                i--;
                j++;
            }
            return j - i - 1;
        }
    string longestPalindrome(string s)
    {
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int op1 = solve(s, i, i + 1);
            int op2 = solve(s, i, i);
            int len = max(op1, op2);

            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};

/*

aabaa

baab

*/