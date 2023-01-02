class Solution
{
    public:
        bool detectCapitalUse(string word)
        {
            bool allcaps = true;
            for (int i = 0; i < word.size(); i++)
            {
                if (word[i] >= 'a'
                    and word[i] <= 'z')
                {
                    allcaps = false;
                    break;
                }
            }
            if (allcaps)
            {
                return true;
            }

            bool allsmall = true;
            for (int i = 0; i < word.size(); i++)
            {
                if (word[i] >= 'A'
                    and word[i] <= 'Z')
                {
                    allsmall = false;
                    break;
                }
            }
            if (allsmall)
            {
                return true;
            }

            bool parialsmall = true;
            for (int i = 1; i < word.size(); i++)
            {
                if (word[i] >= 'A'
                    and word[i] <= 'Z')
                {
                    parialsmall = false;
                    break;
                }
            }
            if (parialsmall and word[0] >= 'A'
                and word[0] <= 'Z')
            {
                return true;
            }
            return false;
        }
};