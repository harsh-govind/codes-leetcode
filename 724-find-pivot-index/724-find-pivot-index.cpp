class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0), leftSum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(totalSum-nums[i]-leftSum==leftSum)
            {
                return i;
            }
            leftSum+=nums[i];
        }
        return -1;
        
    }
};