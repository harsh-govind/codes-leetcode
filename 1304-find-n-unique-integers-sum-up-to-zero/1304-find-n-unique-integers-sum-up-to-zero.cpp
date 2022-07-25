class Solution
{
    public:
        vector<int> sumZero(int n)
        {
            vector<int> ans;
            int i = 0;
            if (n % 2 != 0)
            {
                ans.push_back(0);
                i++;
                while (i <= n / 2)
                {
                    ans.push_back(i);
                    ans.push_back(-i);
                    i++;
                }
                return ans;
            }
            i = 1;
            while (i <= n / 2)
            {
                ans.push_back(i);
                ans.push_back(-i);
                i++;
            }
            return ans;
        }
};