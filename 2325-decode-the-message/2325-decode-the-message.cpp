class Solution
{
    public:
        string decodeMessage(string key, string message)
        {
            unordered_map<char, char> m;
            for (int i = 0, j = 0; i < key.size(); i++)
            {
                if (m.find(key[i]) == m.end() and key[i] != ' ')
                {
                    m[key[i]] = 'a' + (j++);
                }
            }
            string ans;
            for (int i = 0; i < message.size(); i++)
            {
                if (message[i] == ' ')
                {
                    ans += ' ';
                }
                else
                {
                    ans += m[message[i]];
                }
            }
            return ans;
        }
};