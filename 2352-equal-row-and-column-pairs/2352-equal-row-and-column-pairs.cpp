class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> s;
        for(auto &i:grid)
        {
            vector<int> v;
            for(auto &j:i)
            {
                v.push_back(j);
            }
            s[v]++;
        }

        int ans=0;
        for(int i=0; i<grid.size(); i++)
        {
            vector<int> v;
            for(int j=0; j<grid.size(); j++)
            {
                v.push_back(grid[j][i]);
            }
            
            if(s.find(v)!=s.end()) ans+=s[v];
        }
        
        return ans;
    }
};