class Solution
{
    public:
        string reverseVowels(string s)
        {
            string t = "";
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == 'a'
                    or s[i] == 'e'
                    or s[i] == 'i'
                    or s[i] == 'o'
                    or s[i] == 'u' or s[i] == 'A'
                    or s[i] == 'E'
                    or s[i] == 'I'
                    or s[i] == 'O'
                    or s[i] == 'U')
                {
                    t += s[i];
                }
            }
            int p = 0;
            for (int i = s.size() - 1; i >= 0; i--)
            {
                if (s[i] == 'a'
                    or s[i] == 'e'
                    or s[i] == 'i'
                    or s[i] == 'o'
                    or s[i] == 'u' or s[i] == 'A'
                    or s[i] == 'E'
                    or s[i] == 'I'
                    or s[i] == 'O'
                    or s[i] == 'U')
                {
                    s[i] = t[p++];
                }
            }

            return s;
        }
};