class Solution
{
    public:
        int sumOddLengthSubarrays(vector<int> &arr)
        {
            int n = arr.size(), sum = 0;
            for (int i = 0; i < n; i++)
            {

                for (int j = 0; j < n; j++)
                {
                    if ((j - i + 1) % 2 != 0)
                    {
                        for (int k = i; k <= j; k++)
                        {
                            sum += arr[k];
                        }
                    }
                }
            }
            return sum;
        }
};