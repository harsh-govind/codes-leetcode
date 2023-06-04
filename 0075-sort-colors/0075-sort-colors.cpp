class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0, one=0, two=0;
        for(auto &val:nums)
        {
            if(val==0) zero++;
            if(val==1) one++;
            if(val==2) two++;
        }
        int i=0;
        while(zero--)
        {
            nums[i++]=0;
        }
        while(one--)
        {
            nums[i++]=1;
        }
        while(two--)
        {
            nums[i++]=2;
        }
    }
};