class Solution
{
    public:
        int countConsistentStrings(string allowed, vector<string> &words)
        {
            int ans = 0;
            unordered_set<char> check;

            for (int i = 0; i < allowed.size(); i++)
            {
                check.insert(allowed[i]);
            }

            for (int i = 0; i < words.size(); i++)
            {
                unordered_set<char> temp;
                for (int j = 0; j < words[i].size(); j++)
                {
                    temp.insert(words[i][j]);
                }
                bool flag = true;
                for (auto &val: temp)
                {
                    if (check.find(val) == check.end())
                        flag = false;
                }
                if (flag)
                    ans++;
            }
            return ans;
        }
};