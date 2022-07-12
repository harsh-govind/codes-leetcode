class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans="";
        for(int i=0;i<s.size() and k; i++)
        {
            if(s[i]==' ')
            {
                k--;
            }
            if(k!=0)
            ans+=s[i];
        }
        return ans;
    }
};