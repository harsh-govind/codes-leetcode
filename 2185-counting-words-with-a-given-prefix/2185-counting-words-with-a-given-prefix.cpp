class Solution
{
    public:
        int prefixCount(vector<string> &words, string pref)
        {
            int ans = 0;
            for (int i = 0; i < words.size(); i++)
            {
                if (words[i].size() >= pref.size())
                {
                    string s = "";
                    for (int j = 0; j < pref.size(); j++)
                    {
                        s += words[i][j];
                    }
                    if (s == pref)
                        ans++;
                }
            }
            return ans;
        }
};