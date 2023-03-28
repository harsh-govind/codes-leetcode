class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int end=days.back(),dp[end+1];
        dp[0]=0;
        for(int i=1,j=0;i<=end;i++){
            if(i==days[j]){
                j++;
                int a=costs[0]+dp[i-1];
                int b=costs[1]+dp[i-min(i,7)];
                int c=costs[2]+dp[i-min(i,30)];
                dp[i]=min({a,b,c});
            }
            else
                dp[i]=dp[i-1];
        }
        return dp[end];
    }
};