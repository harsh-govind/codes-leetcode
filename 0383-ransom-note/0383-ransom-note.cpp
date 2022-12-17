class Solution
{
    public:
        bool canConstruct(string a, string b)
        {
           	//return true if a can ve contructed by using b
            int am[2556] = { 0 };

            for (int i = 0; i < b.size(); i++)
            {
                am[b[i]]++;
            }
            for (int i = 0; i < a.size(); i++)
            {
                if (am[a[i]] <= 0) return false;
                am[a[i]]--;
            }

            return true;
        }
};