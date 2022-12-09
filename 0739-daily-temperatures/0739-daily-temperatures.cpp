class Solution
{
    public:
        vector<int> dailyTemperatures(vector<int> &t)
        {

            stack<int> stk;
            vector<int> ans(t.size(), 0);

            for (int i = t.size() - 1; i >= 0; i--)
            {
                if (stk.empty())
                {
                    stk.push(i);
                    ans[i] = 0;
                }
                else
                {

                    while (!stk.empty() and t[stk.top()] <= t[i])
                    {
                        stk.pop();
                    }

                    if (stk.size() == 0)
                    {
                        ans[i] = 0;
                        stk.push(i);
                    }
                    else
                    {
                        ans[i] = stk.top() - i;
                        stk.push(i);
                    }
                }
            }
            return ans;
        }
};