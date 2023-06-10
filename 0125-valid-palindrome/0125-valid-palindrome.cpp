class Solution
{
    public:
        bool solve(string &s, int low, int high)
        {
            if(high<=low) return true;
            if(s[low]!=s[high]) return false;
            return solve(s, low+1, high-1);
        }
        bool isPalindrome(string &s)
        {
            string temp = "";
            for (auto &val: s)
            {
                if (val >= 'a'
                    and val <= 'z' || val >= 'A'
                    and val <= 'Z' || val >= '0'
                    and val <= '9')
                {
                    if (val >= 'A'
                        and val <= 'Z')
                    {
                        val = tolower(val);
                    }
                    temp += val;
                }
            }
            return solve(temp, 0, temp.size()-1);
        }
};