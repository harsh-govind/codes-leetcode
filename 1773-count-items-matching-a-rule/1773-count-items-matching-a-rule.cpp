class Solution
{
    public:
        int countMatches(vector<vector < string>> &items, string ruleKey, string ruleValue)
        {
            int ans = 0;
            for (int i = 0; i < items.size(); i++)
            {
                    int a = 0;
                    if (ruleKey == "type")
                        a = 0;
                    else if (ruleKey == "color")
                        a = 1;
                    else
                        a = 2;

                    if (items[i][a] == ruleValue)
                        ans++;
            }
            return ans;
        }
};