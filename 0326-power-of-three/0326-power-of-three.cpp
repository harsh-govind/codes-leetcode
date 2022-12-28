class Solution
{
    public:
        bool isPowerOfThree(int n)
        {
            if (n < 0)
                return false;
            set < long long > s;
            long long check = 1;
            s.insert(1);
            for (int i = 0; i <= 21; i++)
            {
                s.insert(check *= 3);
            }
            return s.find(n) != s.end();
        }
};