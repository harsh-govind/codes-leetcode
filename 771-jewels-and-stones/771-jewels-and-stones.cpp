class Solution
{
    public:
        int numJewelsInStones(string jewels, string stones)
        {
            set<char> check;
            int ans=0;
            for (int i = 0; i < jewels.size(); i++)
            {
                check.insert(jewels[i]);
            }
             for (int i = 0; i < stones.size(); i++)
            {
                if(check.find(stones[i])!=check.end())
                {
                    ans++;
                }
            }
            return ans;
        }
};