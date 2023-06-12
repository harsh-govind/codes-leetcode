class Solution
{
    public:
        int trap(vector<int> &height)
        {
           	//         o(n) o(n)
           	//         int n=height.size();
           	//         vector<int> left(n), right(n);
           	//         left[0]=height[0];
           	//         right[n-1]=height[n-1];

           	//         for(int i=1;i < n;i++)
           	//         {
           	//             left[i]=max(left[i-1], height[i]);
           	//         }
           	//         for(int i=n-2; i>=0; i--)
           	//         {
           	//             right[i]=max(right[i+1], height[i]);
           	//         }

           	//         int ans=0;
           	//         for(int i=0; i < n; i++)
           	//         {
           	//             ans+=min(left[i], right[i])-height[i];
           	//         }

           	//         return ans;

           	//         o(n) o(1);

            int n = height.size();
            int maxLeft = height[0], maxRight = height[n - 1], left = 1, right = n - 2, ans = 0;

            while (left <= right)
            {
                if (maxLeft <= maxRight)
                {
                    if (height[left] > maxLeft)
                    {
                        maxLeft = height[left];
                    }
                    else
                    {
                        ans += maxLeft - height[left];
                    }
                    left++;
                }
                else
                {
                    if (height[right] > maxRight)
                    {
                        maxRight = height[right];
                    }
                    else
                    {
                        ans += maxRight - height[right];
                    }
                    right--;
                }
            }
            return ans;
        }
};