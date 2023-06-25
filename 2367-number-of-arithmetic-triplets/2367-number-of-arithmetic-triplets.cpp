class Solution
{
    public:
        int arithmeticTriplets(vector<int> &nums, int diff)
        {
            unordered_map<int, int> m;
            int ans=0;
            for(auto &v:nums)
            {
                if(m.find(v-diff)!=m.end() and m.find(v-2*diff)!=m.end())
                {
                    ans++;
                }
                m[v]++;
            }

            return ans;
        }
};