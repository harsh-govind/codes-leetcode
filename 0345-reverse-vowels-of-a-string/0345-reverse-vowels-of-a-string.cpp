class Solution
{
    public:
        bool c(char a)
        {
            return (a == 'a'
                or a == 'e'
                or a == 'i'
                or a == 'o'
                or a == 'u'
                or a == 'A'
                or a == 'E'
                or a == 'I'
                or a == 'O'
                or a == 'U');
        }
    string reverseVowels(string a)
    {
       	// string t = "";
       	// for (int i = 0; i < s.size(); i++)
       	// {
       	//     if (c(a[i]))
       	//     {
       	//         t += s[i];
       	//     }
       	// }
       	// int p = 0;
       	// for (int i = s.size() - 1; i >= 0; i--)
       	// {
       	//     if (c(a[i]))
       	//     {
       	//         s[i] = t[p++];
       	//     }
       	// }

        int i = 0, j = a.size() - 1;
        while (i < j)
        {
            if (c(a[i]))
            {
                if (c(a[j]))
                {
                    swap(a[i], a[j]);
                    i++;
                    j--;
                }
                else
                {
                    j--;
                }
            }
            else
            {
                i++;
            }
        }
        return a;
    }
};