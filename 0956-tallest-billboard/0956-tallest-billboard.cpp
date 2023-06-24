class Solution {
public:
   int tallestBillboard(vector<int>& rods)
 {
    unordered_map<int, int> dp;
    dp[0] = 0;
    for (int x : rods)
     {
        unordered_map<int, int> cur(dp);
        for (auto [d, y] : cur)
         {
            dp[d + x] = max(dp[d + x], y);
            dp[abs(d - x)] = max(dp[abs(d - x)], y + min(d, x));
        }
    }
    return dp[0];
 }
};