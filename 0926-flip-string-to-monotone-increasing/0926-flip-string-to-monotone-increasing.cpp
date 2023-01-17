class Solution
{
    public:
        int minFlipsMonoIncr(string s)
        {
            int flip_one = 0, flip_zero = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '1')
                    flip_one++;
                else
                    flip_zero++;
                flip_zero = min(flip_zero, flip_one);
            }
            return flip_zero;
        }
};