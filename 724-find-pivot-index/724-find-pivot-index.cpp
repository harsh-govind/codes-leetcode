class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> leftSum, rightSum;
        
        leftSum.push_back(nums[0]);
        rightSum.push_back(nums[n-1]);
        
        for(int i=1;i<n;i++)
        {
            leftSum.push_back(nums[i]+leftSum[i-1]);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            auto it  = rightSum.end();
            it--;
            rightSum.push_back(*it+nums[i]);            
        }
        for(auto &val:leftSum)
        {
            cout<<val<<" ";
        }
        cout<<endl;
        for(auto &val:rightSum)
        {
            cout<<val<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            if(rightSum[n-i-1]==leftSum[i])
                return i;
        }
        
        return -1;
        
    }
};