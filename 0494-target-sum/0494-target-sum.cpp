class Solution {
public:
    int perfectSum(vector<int> arr, int n, int sum)
    {
        int t[n+1][sum+1];
        for(int i=0;i<=n;i++)
        {
            t[i][0]=1;
        }
        for(int i=1;i<=sum;i++)
        {
            t[0][i]=0;
        }
        
        
        for(int i=1; i<n+1; i++)
        {
            for(int j=0; j<sum+1; j++)
            {
                if(arr[i-1]<=j)
                {
                    t[i][j]=(t[i-1][j-arr[i-1]] + t[i-1][j]);
                }
                else
                {
                    t[i][j] = (t[i-1][j]);
                }
            }
        }
        return t[n][sum];
    }
    int findTargetSumWays(vector<int>& arr, int d) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if((sum-d)%2 != 0 or d>sum) return 0;
        return perfectSum(arr, arr.size(), (sum-d)/2);
    }
};