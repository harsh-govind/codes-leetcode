class Solution
{
    public:
        bool check(int a[], int b[])
        {
            for (int i = 0; i < 26; i++)
            {
                if (a[i] != b[i])
                    return false;
            }
            return true;
        }
    bool checkInclusion(string s1, string s2)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (s1.size() > s2.size())
        {
            return false;
        }

        int a[26] = { 0 };

        for (int i = 0; i < s1.size(); i++)
        {
            a[s1[i] - 'a']++;
        }

        for (int i = 0; i < s2.size() - s1.size() + 1; i++)
        {
            int b[26] = { 0 };
            for (int j = i; j < i + s1.size(); j++)
            {
                b[s2[j] - 'a']++;
            }

            if (check(a, b))
                return true;
        }

        return false;
    }
};