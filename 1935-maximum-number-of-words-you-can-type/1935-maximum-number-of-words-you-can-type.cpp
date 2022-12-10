class Solution
{
    public:
        int canBeTypedWords(string text, string brokenLetters)
        {
            unordered_set<char> st;

            for (int i = 0; i < brokenLetters.size(); i++)
            {
                st.insert(brokenLetters[i]);
            }
            int ans = 0, curr = 0, space = 0;
            for (int i = 0; i < text.size(); i++)
            {
                if (st.find(text[i]) != st.end())
                {
                    curr = 1;
                }

                if (text[i] == ' ') space++;
                if (text[i] == ' '
                    or i == text.size() - 1)
                {

                    ans += curr;
                    curr = 0;
                }
            }
            return space + 1 - ans;
        }
};