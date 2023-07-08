class Solution
{
    public:
        vector<int> relocateMarbles(vector<int> &nums, vector<int> &moveFrom, vector< int > &moveTo)
        {
            map<int, int> m;
            for (auto &val: nums)
            {
                m[val]++;
            }

            for (int i = 0; i < moveFrom.size(); i++)
            {
                int val = m[moveFrom[i]];
                m.erase(moveFrom[i]);
                m[moveTo[i]] = val;
            }

            vector<int> ans;
            for (auto &val: m)
            {
                ans.push_back(val.first);
            }
            return ans;
        }
};