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
                bool flag = true;
                for (int j = 0; j < words[i].size(); j++)
                {
                    if (check.find(words[i][j]) == check.end())
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    ans++;
            }
            return ans;
        }
};