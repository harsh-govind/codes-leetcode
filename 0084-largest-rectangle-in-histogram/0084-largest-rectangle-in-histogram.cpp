class Solution
{
    public:
        int largestRectangleArea(vector<int> &heights)
        {
            int n = heights.size();
            vector<int> left(n);
            stack<pair<int, int>> sleft;

            stack<pair<int, int>> sright;
            vector<int> right(n);
            for (int i = 0; i < n; i++)
            {
                if (sleft.size() == 0)
                {
                    left[i] = -1;
                }
                else if (sleft.size() > 0 and sleft.top().first < heights[i])
                {
                    left[i] = sleft.top().second;
                }
                else if (sleft.size() > 0 and sleft.top().first >= heights[i])
                {
                    while (sleft.size() > 0 and sleft.top().first >= heights[i])
                    {
                        sleft.pop();
                    }

                    if (sleft.size() == 0)
                    {
                        left[i] = -1;
                    }
                    else
                    {
                        left[i] = sleft.top().second;
                    }
                }
                sleft.push({ heights[i], i });
                
                
                if (sright.size() == 0)
                {
                    right[n-i-1] = n;
                }
                else if (sright.size() > 0 and sright.top().first < heights[n-i-1])
                {
                    right[n-i-1] = sright.top().second;
                }
                else if (sright.size() > 0 and sright.top().first >= heights[n-i-1])
                {
                    while (sright.size() > 0 and sright.top().first >= heights[n-i-1])
                    {
                        sright.pop();
                    }

                    if (sright.size() == 0)
                    {
                        right[n-i-1] = n;
                    }
                    else
                    {
                        right[n-i-1] = sright.top().second;
                    }
                }
                sright.push({ heights[n-i-1],n-i-1 });
                
            }

            for (int i = n - 1; i >= 0; i--) {}
            int ans = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                int width = right[i] - left[i] - 1;
                int currArea = heights[i] *width;
                ans = max(ans, currArea);
            }
            return ans;
        }
};