class Solution
{
    public:
        int maxArea(vector<int> &height)
        {
            int ans = INT_MIN, low = 0, high = height.size() - 1;
            while (low <= high)
            {
                int current = (high - low) *min(height[high], height[low]);
                ans = max(ans, current);

                if (height[high] <= height[low])
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }
            return ans;
        }
};