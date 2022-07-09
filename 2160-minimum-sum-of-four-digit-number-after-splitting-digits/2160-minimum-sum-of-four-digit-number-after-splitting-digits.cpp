class Solution
{
    public:
        int minimumSum(int num)
        {
            int ans[5];
            ans[0]=-1;
            for (int i = 1; i < 5; i++)
            {
                ans[i] = num % 10;
                cout<<ans[i]<<" ";
                num /= 10;
            }
            sort(ans, ans + 5);
            int a = ((ans[1] *10) + ans[4]) + ((ans[2] *10) + ans[3]);
            return a;
        }
};