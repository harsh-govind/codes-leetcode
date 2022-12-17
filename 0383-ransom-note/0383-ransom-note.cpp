class Solution
{
    public:
        bool canConstruct(string a, string b)
        {
           	//return true if a can ve contructed by using b
            int am[26] = { 0 };

            for (int i = 0; i < b.size(); i++)
            {
                am[b[i] - 'a']++;
            }
            for (int i = 0; i < a.size(); i++)
            {
                if (am[a[i] - 'a'] <= 0) return false;
                am[a[i] - 'a']--;
            }

            return true;
        }
};