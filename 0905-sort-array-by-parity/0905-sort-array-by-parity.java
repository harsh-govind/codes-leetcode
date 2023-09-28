class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int[] ans = new int[nums.length];
        int low = 0, high = nums.length - 1;
        for (int i:nums) 
        {
            if (i % 2 == 0) 
            {
                ans[low] = i;
                low++;
            } 
            else 
            {
                ans[high] = i;
                high--;
            }
        }
        return ans;
    }
}