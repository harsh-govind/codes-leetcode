class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        char temp;
        bool ans = true;
        for (int i = 0; s[i] != '\0'; i++)
        {
            if(st.empty() && (s[i]== ')' || s[i] == '}' || s[i] == ']'))
            {
                ans = false;
            }
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else if(!st.empty())
            {
                temp = st.top();
                st.pop();
            }
            if (s[i] == '}' && temp != '{')
            {
                ans = false;
            }
            else if (s[i] == ')' && temp != '(')
            {
                ans = false;
            }
            else if (s[i] == ']' && temp != '[')
            {
                ans = false;
            }
        }
        if(st.empty())
            return ans;
        return false;
    }
};