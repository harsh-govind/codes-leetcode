class Solution
{
    public:
        int maximumNumberOfStringPairs(vector<string> &strs)
        {
            unordered_map<string, int> s;
            int ans = 0;
            for (auto &val: strs)
            {
                string temp = val;
                reverse(temp.begin(), temp.end());
                if (s.find(temp) != s.end())
                {
                    ans += s[temp];
                }
                s[val]++;
            }
            return ans;
        }
};