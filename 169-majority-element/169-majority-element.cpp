class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto &val:nums)
        {
            m[val]++;
        }
                
        for(auto &val:m)
        {
            if(val.second>nums.size()/2)
            {
                return val.first;
            }
        }
        return 0;
    }
};