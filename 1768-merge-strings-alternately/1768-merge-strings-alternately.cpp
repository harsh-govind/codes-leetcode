class Solution
{
    public:
        string mergeAlternately(string word1, string word2)
        {
            int i = 0, j = 0;
            int t = 1;
            string s = "";
            while (i < word1.size() && j < word2.size())
            {
                if (t & 1)
                {
                    s += word1[i];
                    i++;
                }
                else
                {
                    s += word2[j];
                    j++;
                }
                t++;
            }
            while (i < word1.size())
            {
                s += word1[i];
                i++;
            }
            while (j < word2.size())
            {
                s += word2[j];
                j++;
            }
            return s;
        }
};