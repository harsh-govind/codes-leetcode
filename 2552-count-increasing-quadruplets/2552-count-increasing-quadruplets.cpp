class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> M=vector<vector<int>>(n,vector<int>(n,0)),&L=M,&R=M;
        for(int j=2;j<n-1;j++) //O(N^2) calculate prefix sum of count for L
            for(int h =0;h<j-1;h++) 
                L[j][h] =  (h-1<0?0:L[j][h-1]) + (nums[h]<nums[j]);
        for(int i=1;i<n-2;i++) ////O(N^2) calculate suffix sum of count for R
            for(int k=n-1;k>i+1;k--)
                R[i][k] = (k+1>=n?0:R[i][k+1]) + (nums[k]>nums[i]);
        long long ans = 0;
        for(int i=1;i<n-2;i++) 
            for(int j=i+1;j<n-1;j++) 
                if(nums[i]>nums[j]) 
                    ans += (long long)L[j][i-1]*(long long)R[i][j+1];
        return ans;
    }
};