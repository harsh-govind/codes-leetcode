class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        for(int i=0; i<s.size(); i++)
        {
          if(s[i]=='(')
          {
            stk.push(i);
          }
          else
          {
            if(stk.size()>0 and s[stk.top()]=='(')
            {
              stk.pop();
            }
            else
            {
              stk.push(i);
            }
          } 
        }

        int len=s.size(), mx=0;
        while(!stk.empty())
        {
          int top=stk.top();
          stk.pop();
          mx=max(mx, len-top-1);
          len=top;
        }    
        return max(len, mx);
    }
};