class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            unordered_map<char, int> st;
            int ans = 0, currAns = 0;
            if (s.size() == 1)
            {
                return 1;
            }
            for (int i = 0; i < s.size(); i++)
            {
                if (st.find(s[i]) == st.end())
                {
                    st[s[i]] = i;
                    currAns++;
                    ans = max(ans, currAns);
                }
                else
                {
                    ans = max(ans, currAns);
                    currAns = 1;
                    int temp = st[s[i]]+1;
                    st.erase(st.begin(), st.end());
                    i=temp;
                    st[s[i]]=i;
                }
            }
            return ans;
        }
};