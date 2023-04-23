class Solution {
public:
    int mod = 1e9 + 7;

    // Number of possible splits for substring s[start ~ m-1].
    int dfs(vector<int>& dp, int start, string& s, int k) {
        // If we have already updated dp[start], return it.
        if (dp[start] != 0)
            return dp[start];

        // There is only 1 split for an empty string.
        if (start == s.length())
            return 1;

        // Number can't have leading zeros.
        if (s[start] == '0')
            return 0;

        // For all possible starting number, add the number of arrays 
        // that can be printed as the remaining string to count.
        int count = 0;
        for (int end = start; end < s.length(); ++end) {
            string currNumber = s.substr(start, end - start + 1);
            if (stoll(currNumber) > k)
                break;
            count = (count + dfs(dp, end + 1, s, k)) % mod;
        }

        // Update dp[start] so we don't recalculate it later.
        dp[start] = count;
        return count;
    }

    int numberOfArrays(string s, int k) {
        int m = s.length();
        vector<int> dp(m + 1);
        return dfs(dp, 0, s, k);
    }
};