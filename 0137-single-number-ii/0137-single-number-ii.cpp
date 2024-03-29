class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto &val:nums)
        {
            m[val]++;
        }
        
        for(auto &val:m)
        {
            if(val.second==1)
            {
                return val.first;
            }
        }
        return -1;
    }
};