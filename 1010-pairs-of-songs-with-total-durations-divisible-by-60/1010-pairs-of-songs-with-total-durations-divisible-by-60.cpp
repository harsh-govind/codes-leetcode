class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> m;
        int ans=0;
        for(auto &val:time)
        {
            int curr=val%60;
            
            if(curr==0)
            {
                if(m.find(curr)!=m.end())
                {
                    ans+=m[curr];
                }
            }
            else
            {
                if(m.find(60-curr)!=m.end())
                {
                    ans+=m[60-curr];
                }
            }
            
            m[curr]++;
        }
        return ans;
    }
};