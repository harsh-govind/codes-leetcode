class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin1=INT_MAX, currMin2=INT_MAX, profit1=0, profit2=0;
        
        for(auto &val:prices)
        {
            currMin1=min(currMin1, val);
            int currProfit1=val-currMin1;
            profit1=max(profit1, currProfit1);
            
            currMin2=min(currMin2, val-profit1);
            int currProfit2=val-currMin2;
            profit2=max(profit2, currProfit2);
        }
        return profit2;
    }
};