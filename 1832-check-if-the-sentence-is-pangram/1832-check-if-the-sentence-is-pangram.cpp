class Solution
{
    public:
        bool checkIfPangram(string s)
        {
            unordered_map<char, int> m;

            for (int i = 0; i < s.size(); i++)

            {
                m[s[i]]++;

            }

            for (int i = 'a'; i <= 'z'; i++)
            {
                if (m.find(i) == m.end())
                {
                    return false;
                }
            }

            return true;
        }
};