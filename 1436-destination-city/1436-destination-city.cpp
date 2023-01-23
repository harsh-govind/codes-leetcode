class Solution
{
    public:
        string destCity(vector<vector < string>> &paths)
        {
            unordered_set<string> s;

            for (auto &val: paths)
            {
                s.insert(val[0]);
            }

            for (auto &val: paths)
            {
                if (s.find(val[1]) == s.end())
                {
                    return val[1];
                }
            }
            return "";
        }
};