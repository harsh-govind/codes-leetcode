class Solution
{
    public:
        int findKthPositive(vector<int> &arr, int k)
        {
            unordered_set<int> s;
            for (auto &val: arr)
            {
                s.insert(val);
            }
            vector<int> v;
            for (int i = 1; i <= 10000; i++)
            {
                if (s.find(i) == s.end())
                {
                    v.push_back(i);
                }
            }

            return v[k - 1];
        }
};