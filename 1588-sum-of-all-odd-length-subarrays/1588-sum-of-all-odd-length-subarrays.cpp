class Solution
{
   	//https://www.youtube.com/watch?v=J5IIH35EBVE
    public:
        int sumOddLengthSubarrays(vector<int> &arr)
        {
            int n = arr.size(), sum = 0;
            for (int i = 0; i < n; i++)
            {
                int start = n - i, end = i + 1;
                int total = start * end;
                int odd = (total + 1) / 2;
                sum += odd *arr[i];
            }
            return sum;
        }
};