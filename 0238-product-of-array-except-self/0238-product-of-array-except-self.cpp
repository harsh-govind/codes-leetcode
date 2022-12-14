class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &v)
        {
            int n = v.size();
            int pro = 1;
            vector<int> ans;

            for (int i = 0; i < n; i++)
            {
                ans.push_back(pro = pro *v[i]);
            }

            for (auto &val: ans)
            {
                cout << val << " ";
            }
            cout << endl;

            pro = 1;

            for (int i = n - 1; i >= 0; i--)
            {
                if (i == n - 1)
                {
                    ans[i] = ans[i - 1];
                    pro = v[i];
                }
                else if (i == 0)
                {
                    ans[i] = pro;
                }
                else
                {
                    ans[i] = pro *ans[i - 1];
                    pro *= v[i];
                }
            }

            return ans;
        }
};