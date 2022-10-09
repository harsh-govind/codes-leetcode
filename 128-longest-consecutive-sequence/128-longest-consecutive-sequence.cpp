class Solution
{
    public:

        int longestConsecutive(vector<int> &k)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);

            unordered_set<int> s;

            for (auto &v: k)
            {
                s.insert(v);
            }
            int ans = 0, currAns = 0;
            for (auto &v: k)
            {
                currAns = 1;
                if (s.find(v - 1) == s.end())
                {
                    int temp = v;
                    while (s.find(temp+1) != s.end())
                    {
                        currAns++;
                        temp++;
                    }
                    ans = max(ans, currAns);
                }
            }
            return ans;
        }
};