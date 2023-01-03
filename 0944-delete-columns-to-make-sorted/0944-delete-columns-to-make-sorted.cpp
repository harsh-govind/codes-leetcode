class Solution
{
    public:
        int minDeletionSize(vector<string> &strs)
        {
            int ans = 0;
            for (int i = 0; i < strs[0].size(); i++)
            {
                string word = "";
                for (int j = 0; j < strs.size(); j++)
                {
                    word += strs[j][i];
                }
                string sortedword = word;
                sort(sortedword.begin(), sortedword.end());
                if (sortedword != word)
                {
                    ans++;
                }
            }
            return ans;
        }
};