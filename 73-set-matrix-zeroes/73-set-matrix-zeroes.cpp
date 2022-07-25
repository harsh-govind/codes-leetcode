class Solution
{
    public:
        void setZeroes(vector<vector <int>> &vec)
        {
            int m=vec.size(), n=vec[0].size();
            unordered_set<int> r, c;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(vec[i][j]==0)
                    {
                        r.insert(i);
                        c.insert(j);
                    }
                }
            }
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(r.find(i)!=r.end() or c.find(j)!=c.end())
                    {
                        vec[i][j]=0;
                    }
                }
            }
        }
};