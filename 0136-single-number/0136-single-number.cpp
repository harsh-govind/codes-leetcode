class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(auto &val:nums)
        {
            x^=val;
        }
        return x;
    }
};