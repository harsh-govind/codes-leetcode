class Solution {
public:
    string reverseWords(string s) {
        stack<char> ss;
        string ans="";
        for(auto &c:s)
        {
            if(c==' ')
            {
                while(!ss.empty())
                {
                    ans+=ss.top();
                    ss.pop();
                }
                ans+=c;
            }
            else
            {
                ss.push(c);
            }
        }
        while(!ss.empty())
        {
            ans+=ss.top();
            ss.pop();
        }
        return ans;
    }
};