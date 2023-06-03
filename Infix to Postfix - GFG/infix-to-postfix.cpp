//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int prec(char c)
    {
        if(c=='^') return 3;
        if(c=='/' or c=='*') return 2;
        if(c=='+' or c=='-') return 1;
        return 0;
    }
    string infixToPostfix(string s) {
        string ans="";
        stack<char> stk;
        for(int i=0; i<s.size(); i++)
        {
            if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z') or (s[i]>='0' and s[i]<='9'))
            {
                ans+=s[i];
            }
            else if(s[i]=='(')
            {
                stk.push(s[i]);
            }
            else if(s[i]==')')
            {
                while(stk.size()>0 and stk.top()!='(')
                {
                    ans+=stk.top();
                    stk.pop();
                }
                if(stk.size()>0)
                {
                    stk.pop();
                }
            }
            else
            {
                while(stk.size()>0 and prec(stk.top())>=prec(s[i]))
                {
                    ans+=stk.top();
                    stk.pop();
                }
                stk.push(s[i]);
            }
        }
        while(stk.size()>0)
        {
            ans+=stk.top();
            stk.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends