class Solution
{
    public:
        int maxArea(vector<int> &a)
        {
            int mx = INT_MIN, currMax = INT_MIN, n = a.size();
            int l = 0, h = n - 1;
            while (l < h)
            {
                int temp = min(a[l], a[h]);
                currMax = max(currMax, temp *(h - l));
                mx = max(mx, currMax);
                if (a[h] > a[l])
                {
                    l++;
                }
                else if (a[h] < a[l])
                {
                    h--;
                }
                else
                {
                    h--;
                    l++;
                }
            }
            return mx;
        }
};