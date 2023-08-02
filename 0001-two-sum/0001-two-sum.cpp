class Solution
{
    public:
        vector<int> twoSum(vector<int> &v, int key)
        {
            //trip trip tripteip trip trip
            //Try try
            // 20. Valid Parentheses upoaded
            // 20. Valid Parentheses upoaded
            // uploaded
            // uploaded
            //done yes
            unordered_map<int, int> s;
            int n = v.size();
            vector<int> ans;
            for (int i = 0; i < n; i++)
            {
                if (s.find(key - v[i]) != s.end())
                {
                    //temp
                    ans.push_back(i);
                    ans.push_back(s[key - v[i]]);
                    return ans;
                }
                s[v[i]] = i;
            }
            return ans;
        }
};
