class Solution
{
    public:
        char findTheDifference(string s, string t)
        {

            unordered_map<char, int> st;

            for (int i = 0; i < s.size(); i++)
            {
                st[s[i]]++;
            }

            for (int i = 0; i < t.size(); i++)
            {
                st[t[i]]++;
            }

            for (auto &val: st)
            {
                cout<<val.first<<val.second<<endl;
                if (val.second%2 !=0)
                    return val.first;
            }
            return ' ';
        }
};