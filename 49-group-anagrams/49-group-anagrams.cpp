class Solution
{
    public:
        vector<vector < string>> groupAnagrams(vector<string> &a)
        {
            unordered_map<string, vector < string>> m;

            for (auto &val: a)
            {
                string temp = val;
                sort(temp.begin(), temp.end());
                m[temp].push_back(val);
            }

            vector<vector < string>> ans;

            for (auto &val: m)
            {
                vector<string> temp;
                for (auto &val1: val.second)
                {
                    temp.push_back(val1);
                }
                ans.push_back(temp);
            }

            return ans;
        }
};