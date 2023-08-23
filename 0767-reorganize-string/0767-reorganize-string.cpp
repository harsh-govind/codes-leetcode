class Solution
{
    public:
        string reorganizeString(string s)
        {
            unordered_map<char, int> m;
            priority_queue<pair<int, char>> p;
            for (auto &val: s)
            {
                m[val]++;
            }
            for (auto &val: m)
            {
                p.push({ val.second,
                    val.first });
            }
            string ans = "";
            pair<int, char> block = { -1,
                '#' };
            while (p.size() > 0)
            {
                auto temp = p.top();
                p.pop();
                ans += temp.second;
                temp.first--;

                if (block.first > 0)
                {
                    p.push(block);
                }
                block = temp;
            }
            return ans.size() == s.size() ? ans : "";
        }
};