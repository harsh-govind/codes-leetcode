class Solution
{
    public:
        bool isAnagram(string a, string b)
        {
            unordered_map<char, int> ma, mb;
            for (int i = 0; i < a.size(); i++)
            {
                ma[a[i]]++;
            }
            for (int i = 0; i < b.size(); i++)
            {
                mb[b[i]]++;
            }
            if (ma == mb)
                return true;
            return false;
        }
};