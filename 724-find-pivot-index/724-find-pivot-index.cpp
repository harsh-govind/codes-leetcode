class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> rightSum;
        
        rightSum.push_back(nums[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            auto it  = rightSum.end();
            it--;
            rightSum.push_back(*it+nums[i]);            
        }
        int leftSum=0;
        for(int i=0;i<n;i++)
        {
            leftSum+=nums[i];
            if(rightSum[n-i-1] == leftSum)
                return i;
        }
        
        return -1;
        
    }
};