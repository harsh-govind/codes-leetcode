class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0.0, ans=INT_MIN;
        for(int i=0; i<k-1; i++)
        {
            sum+=nums[i];
        }
        int low, high=k-1;
        while(high<nums.size())
        {
            sum+=nums[high++];
            ans=max(sum/k, ans);
            sum-=nums[low++];   
        }
        return ans;
    }
};