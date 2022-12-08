class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0, n=nums.size();
        
        for(int j=0; j<n;j++)
        {
            if(i<j)
                return false;
            
            i = max(i, j+nums[j]);
        }
        return true;
    }
};