class Solution {
    public int differenceOfSum(int[] nums) {
        int arrSum=0;
        
        for(int i=0; i<nums.length; i++)
        {
            arrSum+=nums[i];
        }
        
        int digSum=0;
        
        for(int i=0; i<nums.length; i++)
        {
            
            int currSum=0;
            
            while(nums[i]>0)
            {
                currSum+=nums[i]%10;
                nums[i]/=10;
            }
            
            digSum+=currSum;
        }
        
        return Math.abs(digSum-arrSum);
        
        
    }
}