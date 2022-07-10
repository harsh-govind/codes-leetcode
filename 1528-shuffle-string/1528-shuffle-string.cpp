class Solution
{
    public:
        string restoreString(string s, vector<int> &indices)
        {
            string ans=s;
            int i=0;
            for(auto &val:indices)
            {
                ans[val]=s[i++];
            }
            return ans;
        }
};