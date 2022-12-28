class Solution
{
    public:
        int pivotInteger(int n)
        {
            int sum = n *(n + 1) / 2;

            int currSum = 0, i = 1;

            while (i <= n)
            {

                if (currSum == (sum - currSum - i))
                {
                    return i;
                }
                currSum += i;
                i++;
            }

            return -1;
        }
};