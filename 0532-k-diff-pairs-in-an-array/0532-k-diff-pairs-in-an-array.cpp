class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int, int>> t;
        unordered_set<int> s;
        int ans=0;
        for(auto &val:nums)
        {
            int target1=(val-k);
            if(s.find(target1)!=s.end())
            {
                t.insert({target1, val});
            }
            int target2=(k+val);
            if(s.find(target2)!=s.end())
            {
                t.insert({val, target2});
            }
                
            s.insert(val);

        }
        return t.size();
    }
};