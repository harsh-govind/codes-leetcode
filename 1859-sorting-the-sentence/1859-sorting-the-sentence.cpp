class Solution
{
    public:
        string sortSentence(string s)
        {
            map<int, string> m;

            string temp = "";
            for (int i= 0; i < s.size(); i++)
            {
                if (s[i] >= '1'
                    and s[i] <= '9')
                {
                    m[s[i]-'0'] = temp;
                    temp = "";
                }
                else if (s[i] != ' ')
                {
                    temp += s[i];
                }
            }
            string ans="";
            for (auto &val: m)
            {
                cout << val.first << " " <<val.second << endl;
                ans+=val.second;
                ans+=' ';
            }
            
            
            return string(ans.begin(), ans.end()-1);
        }
};