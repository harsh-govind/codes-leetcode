class Solution
{
    public:
        bool isAlienSorted(vector<string> &words, string order)
        {
            std::ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
            unordered_map<char, int> mp;
            int ch = 'a';
            for (char c: order)
                mp[c] = ch++;
            for (string &s: words)
            {
                for (char &c: s)
                    c = mp[c];
            }
            vector<string> copied = words;
            sort(begin(copied), end(copied));
            return copied == words;
        }
};