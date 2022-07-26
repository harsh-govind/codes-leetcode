class Solution
{
    public:
    int check[10][3];

    int countPoints(string rings)
    {
        for (int i = 0; i < rings.size(); i += 2)
        {
            if(rings[i]=='R')
            {
                check[rings[i+1]-'0'][0]=1;
            }
            if(rings[i]=='G')
            {
                check[rings[i+1]-'0'][1]=1;
            }
            if(rings[i]=='B')
            {
                check[rings[i+1]-'0'][2]=1;
            }
        }
        int ans=0;
        for(int i=0;i<10;i++)
        {
            if(check[i][0] + check[i][1]+ check[i][2]==3)
            {
                ans++;
            }
        }
        return ans;
    }
};