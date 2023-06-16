class Solution
{
    public:
        void solve(string &s, int minRemoval, unordered_set<string> &check, vector<string> &ans)
        {
            if (minRemoval == 0)
            {
                if (getMin(s) == 0)
                {
                    ans.push_back(s);
                }
                return;
            }

            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != ')'
                    and s[i] != '(') continue;
                string left = s.substr(0, i), right = s.substr(i + 1);
                string newS = left + right;
                if(check.find(newS)==check.end())
                {
                    check.insert(newS);
                    solve(newS, minRemoval - 1, check, ans);
                }
            }
        }
    int getMin(string & s)
    {
        stack<char> stk;
        for (auto &val: s)
        {
            if (val != '('
                and val != ')') continue;
            if (val == '('
                or stk.empty())
            {
                stk.push(val);
            }
            else
            {
                if (stk.top() == '(')
                {
                    stk.pop();
                }
                else if (stk.top() == ')')
                {
                    stk.push(val);
                }
            }
        }

        return stk.size();
    }
    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> ans;
        int minRemoval = getMin(s);
        unordered_set<string> check;
        solve(s, minRemoval, check, ans);
        return ans;
    }
};