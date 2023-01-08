class Solution
{
    public:
        int findFinalValue(vector<int> &nums, int original)
        {
            unordered_set<int> st;
            for (auto &val: nums)
            {
                st.insert(val);
            }
            while (st.find(original) != st.end())
            {
                original=(original*2);
            }

            return original;
        }
};