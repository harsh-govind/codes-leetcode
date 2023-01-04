class Solution
{
    public:
        string oddString(vector<string> &words)
        {
            map<vector < int>, int> mp;

            for (auto &word: words)
            {
                vector<int> temp;
                for (int i = 0; i < word.size() - 1; i++)
                {
                    temp.push_back((word[i + 1] - 'a') - (word[i] - 'a'));
                }

                mp[temp]++;
            }
            vector<int> key;
            for (auto &val: mp)
            {
                cout << val.second << " ";
                if (val.second == 1)
                {
                    key = val.first;
                }
            }
            for (auto &word: words)
            {
                vector<int> temp;
                for (int i = 0; i < word.size() - 1; i++)
                {
                    temp.push_back((word[i + 1] - 'a') - (word[i] - 'a'));
                }

                if (temp == key)
                {
                    return word;
                }
            }
            return "";
        }
};