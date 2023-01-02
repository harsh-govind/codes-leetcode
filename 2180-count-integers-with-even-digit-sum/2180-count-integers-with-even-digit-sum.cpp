class Solution
{
    public:
        bool iseven(int num)
        {
            int sum = 0;
            while (num > 0)
            {
                sum += num % 10;
                num /= 10;
            }
            return (sum % 2) == 0;
        }
    int countEven(int num)
    {
        int ans = 0;
        for (int i = 1; i <= num; i++)
        {
            if (iseven(i))
            {
                ans++;
            }
        }
        return ans;
    }
};