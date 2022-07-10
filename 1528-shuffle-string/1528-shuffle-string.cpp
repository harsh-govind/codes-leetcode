class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans="";
        map<int, char> m;
        for(int i=0;i<s.size();i++)
        {
            m[indices[i]]=s[i];
        }
        for(auto &val:m)
        {
            ans+=val.second;
        }
        return ans;
    }
};