class Solution
{
    public:
        int mostWordsFound(vector<string> &sentences)
        {
            int currAns = 0, ans = 0;
            for (auto &val: sentences) {
                currAns=0;
                for(int i=0;i<val.size();i++)
                {
                    if(val[i]==' ')
                    {
                        currAns++;
                    }
                }
                ans=max(currAns, ans);
            }
            return ans+1;
        }
};