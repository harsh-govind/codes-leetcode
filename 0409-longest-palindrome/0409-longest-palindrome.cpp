class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int> m;
        for(auto &c:s)
        {
            m[c]++;
        }
        
        int ans = 0;
        bool hasOddCount = false;

        for (auto &p : m) {
            if (p.second % 2 == 0) {
                ans += p.second;
            } else {
                ans += p.second - 1;
                hasOddCount = true;
            }
        }

        if (hasOddCount) {
            ans++; 
        }
        
        return ans;
    }
};