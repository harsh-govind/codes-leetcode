class Solution
{
    public:
        int peakIndexInMountainArray(vector<int> &arr)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);

            int l = 1, h = arr.size() - 2;

            while (l <= h)
            {
                int m = (l + h) / 2;

                if (arr[m] > arr[m - 1] and arr[m] > arr[m + 1])
                {
                    return m;
                }
                else if (arr[m] > arr[m - 1] and arr[m] < arr[m + 1])
                {
                    l = m + 1;
                }
                else
                {
                    h = m - 1;
                }
            }

            return -1;
        }
};