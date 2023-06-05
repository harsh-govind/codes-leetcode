class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, num=0;
        for(auto &val:nums)
        {
            if(count==0)
            {
                num=val;
            }
            if(val==num) count++;
            else count--;
        }
        return num;
    }
};