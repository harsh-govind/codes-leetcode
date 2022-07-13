class Solution
{
    public:
        int largestAltitude(vector<int> &gain)
        {
            int ans = 0, mx = 0;
            for (int i = 0; i < gain.size(); i++)
            {
                mx+=gain[i];
                if(mx>ans)
                {
                    ans=mx;
                }
            }
            return ans;
        }
};