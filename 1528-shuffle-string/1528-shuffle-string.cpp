class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans="";
        unordered_map<int, char> m;
        for(int i=0;i<s.size();i++)
        {
            m[indices[i]]=s[i];
        }
        for(int i=0;i<s.size();i++)
        {
            ans+=m[i];
        }
        return ans;
    }
};