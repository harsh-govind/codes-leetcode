class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        unordered_set<char> row1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'}, row2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'}, row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

        vector<string> ans;;

        for (string word : words)
        {
            int r = 0;
            if (row1.count(tolower(word[0])))
                r = 1;
            else if (row2.count(tolower(word[0])))
                r = 2;
            else
                r = 3;

            bool flag = true;
            for (char c : word)
            {
                if (r == 1 && !row1.count(tolower(c)))
                {
                    flag = false;
                    break;
                }
                else if (r == 2 && !row2.count(tolower(c)))
                {
                    flag = false;
                    break;
                }
                else if (r == 3 && !row3.count(tolower(c)))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(word);
        }
        return ans;
    }
};