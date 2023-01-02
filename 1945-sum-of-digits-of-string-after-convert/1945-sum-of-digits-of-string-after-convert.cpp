class Solution
{
    public:
        int getLucky(string s, int k)
        {
            string num = "";
            for (int i = 0; i < s.size(); i++)
            {
                int temp = s[i] - 'a' + 1;
                num += to_string(temp);
            }
            int i = k;
            while (k--)
            {
                int temp = 0;
                for (int i = 0; i < num.size(); i++)
                {
                    temp += num[i] - '0';
                }
                num = to_string(temp);
            }
            return stoi(num);
        }
};