class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto &val:nums)
        {
            if(m.find(val)==m.end())
            {
                m[val]=1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};