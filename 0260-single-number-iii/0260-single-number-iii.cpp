class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto &val:nums)
        {
            m[val]++;
        }
        
        vector<int> ans;
        for(auto &val:m)
        {
            if(val.second==1)
            {
                ans.push_back(val.first);
            }
        }
        return ans;
    }
};