class Solution
{
    public:
        int strStr(string hay, string nee)
        {
            if (hay.size() < nee.size())
            {
                return -1;
            }
            else if (hay == nee)
                return 0;
            int n = hay.size(), m = nee.size();

            for (int i = 0; i < hay.size() - m+1; i++)
            {
                string a = string(hay.begin() + i, hay.begin() + m + i);
                if (a == nee) return i;
            }

            return -1;
        }
};