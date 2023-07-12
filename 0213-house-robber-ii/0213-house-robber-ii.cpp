class Solution {
public:
    int solve(vector<int>& nums, int low, int high) {
        int prev1=nums[low], prev2=0;
        for(int i=low+1; i<=high; i++)
        {
            int incl=nums[i]+prev2;
            int excl=prev1;

            int ans=max(incl, excl);

            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return nums[0];
        
        int op1=solve(nums, 0, n-2);
        int op2=solve(nums, 1, n-1);
        
        return max(op1, op2);
    }
};