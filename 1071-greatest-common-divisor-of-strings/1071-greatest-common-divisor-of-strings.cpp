class Solution
{
    public:
        string gcdOfStrings(string str1, string str2)
        {
            std::ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
            if (str1 + str2 != str2 + str1)
            {
                return "";
            }

            int gcdLength = gcd(str1.size(), str2.size());
            return str1.substr(0, gcdLength);
        }
};