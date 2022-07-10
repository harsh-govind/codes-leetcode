class Solution
{
    public:
        int search(vector<int> &a, int key)
        {
            int l = 0, mid, h = a.size() - 1;
            while (l <= h)
            {
                mid = (l + h) / 2;
                if (a[mid] == key)
                {
                    return mid;
                }
                if (a[l]<=a[mid])
                {
                    if(key>=a[l] and key<a[mid])
                    {
                        h=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                    }
                }
                else
                {
                    if(key<=a[h] and key>a[mid])
                    {
                        l=mid+1;
                    }
                    else
                    {
                        h=mid-1;
                    }
                }
            }
            return -1;
        }
};