class Solution
{
    public:
        int findMin(vector<int> &a)
        {
            int l = 0, h = a.size() - 1, mid;
            while (l < h)
            {
                mid = l + (h - l) / 2;
                if (mid > 0 and a[mid - 1] > a[mid])
                {
                    return a[mid];
                }
                if (a[l] <= a[mid] and a[mid] > a[h])
                {
                    l = mid + 1;
                }
                else
                {
                    h = mid - 1;
                }
            }
            return a[l];
        }
};