class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, num=0;
        for(auto &val:nums)
        {
            count==0?num=val:num=num;
            val==num?count++:count--;
        }
        return num;
    }
};