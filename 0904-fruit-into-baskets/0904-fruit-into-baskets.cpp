class Solution {
public:
    int totalFruit(vector<int>& v) {
        
        if(v.size()<=2)
            return v.size();
        int start=0;
        int end=0;
        map<int,int>mp;
        int maxi=INT_MIN;
        for(int end=0;end<v.size();end++)
        {
            mp[v[end]]++;
            
            while(mp.size()>2 && start<end)
            {
                mp[v[start]]--;
                if(mp[v[start]]==0)
                    mp.erase(v[start]);
                start++;
            }
            maxi=max(maxi,end-start+1);
        }
        return maxi;
        
        
        
    }
};