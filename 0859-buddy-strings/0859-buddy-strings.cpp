#include <vector>
#include <string>

class Solution
{
    public:
        bool buddyStrings(string s, string goal)
        {
            int count = 0;
            vector<int> idx;
            if (s.size() != goal.size())
                return false;
            if (s == goal)
            {
                vector<int> freq(26, 0);
                for (char &c: s)
                {
                    freq[c - 'a']++;
                    if (freq[c - 'a'] > 1)
                        return true;
                }
                return false;
            }

            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != goal[i])
                {
                    count++;
                    if (count > 2)
                        return false;
                    idx.push_back(i);
                }
            }

            if (count != 2)
                return false;

            swap(s[idx[0]], s[idx[1]]);

            return s == goal;
        }
};