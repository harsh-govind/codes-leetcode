class Solution
{
    public:
        bool areOccurrencesEqual(string s)
        {
            unordered_map<char, int> mp;
            int check = 0;
            for (int i = 0; i < s.size(); i++)
            {
                mp[s[i]]++;

                if (i == s.size() - 1)
                {
                    check = mp[s[i]];
                }
            }

            for (auto &v: mp)
            {
                if (v.second != check)
                    return false;
            }

            return true;
        }
};