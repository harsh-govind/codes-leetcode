class Solution
{
    public:
        string frequencySort(string s)
        {
            unordered_map<char, int> arr;
            for (int i = 0; i < s.size(); i++)
            {
                arr[s[i]]++;
            }
            multimap<int, char, greater < int>> fn;
            for (auto &val: arr)
            {
                fn.insert(make_pair(val.second, val.first));
            }
            string ans = "";
            for (auto &val: fn)
            {
                for (int i = 0; i < val.first; i++)
                {
                    ans += val.second;
                }
            }
            return ans;
        }
};