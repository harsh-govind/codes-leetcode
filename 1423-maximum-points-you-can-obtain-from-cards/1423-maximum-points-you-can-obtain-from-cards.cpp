class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int n=cards.size(), ans=INT_MIN, sum=0;
        vector<int> arrSum(n, 0);
        for(int i=0; i<n; i++)
        {
            sum+=cards[i];
            arrSum[i]=sum;
        }
        if(k==n) return sum;
        
        for(int i=0; i<=k; i++)
        {
            int low=i, high=i+(n-k-1);
            
            int curr;
            if(i==0)
            {
                curr=sum-arrSum[high];
            }
            else
            {
                curr=sum-arrSum[high]+arrSum[low-1];
            }
                    
            ans=max(ans, curr);
        }
        return ans;
    }
};