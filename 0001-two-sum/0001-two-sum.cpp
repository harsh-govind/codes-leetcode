class Solution
{
public:
    vector<int> twoSum(vector<int> &v, int key)
    {
        // test
        unordered_map<int, int> s;
        int n = v.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (s.find(key - v[i]) != s.end())
            {
                // temp
                ans.push_back(i);
                ans.push_back(s[key - v[i]]);
                return ans;
            }
            s[v[i]] = i;
        }
        return ans;
    }
};
