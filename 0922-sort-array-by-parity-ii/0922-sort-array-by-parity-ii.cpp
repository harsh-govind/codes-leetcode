class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odd, even;
        
        for(auto &val:nums)
        {
            if(val%2==0)
            {
                even.push_back(val);
            }
            else
            {
                odd.push_back(val);
            }
        }
        
        int i=0, j=0;
        
        for(int k=0; k<nums.size(); k++)
        {
            if(k%2==0)
            {
                nums[k]=even[i++];
            }
            else
            {
                nums[k]=odd[j++];
            }
        }
        return nums;
    }
};