class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            unordered_map<char, int> st;
            int ans = 0, l = 0, r = 0;
            while (r < s.size())
            {
                if (st.find(s[r]) != st.end())
                {
                    l = max(l, st[s[r]] + 1);
                }
                st[s[r]] = r;

                ans = max(ans, r - l + 1);
                r++;
            }
            return ans;
        }
};