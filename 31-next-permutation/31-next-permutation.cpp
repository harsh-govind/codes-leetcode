class Solution
{
    public:
        void nextPermutation(vector<int> &a)
        {
            int n = a.size(), l, h;
            for (l = n - 2; l >= 0; l--)
            {
                if (a[l] < a[l + 1])
                {
                    break;
                }
            }
            if (l < 0)
            {
                reverse(a.begin(), a.end());
            }
            else
            {
                for (h = n - 1; h > l; h--)
                {
                    if (a[h] > a[l])
                    {
                        break;
                    }
                }
                swap(a[l], a[h]);
                reverse(a.begin() + l + 1, a.end());
            }
        }
};