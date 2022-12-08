class Solution
{
    public:
        int lb(vector<int> &v, int key)
        {
            int s = 0;
            int e = v.size() - 1;
            int mid;
            int ans = -1;
            while (s <= e)
            {
                mid = (s + e) / 2;
                if (v[mid] == key)
                {
                    ans = mid;
                    e = mid - 1;
                }
                else if (v[mid] > key)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            return ans;
        }
   	//upper bound binary search
    int ub(vector<int> &v, int key)
    {
        int s = 0;
        int e = v.size() - 1;
        int mid;
        int ans = -1;
        while (s <= e)
        {
            mid = (s + e) / 2;
            if (v[mid] == key)
            {
                ans = mid;
                s = mid + 1;
            }
            else if (v[mid] > key)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int> &v, int target)
    {
        vector<int> ans;

        int a = lb(v, target);
        int b = ub(v, target);
        
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};