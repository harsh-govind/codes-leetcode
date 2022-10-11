class Solution {

    public int minStartValue(int[] nums) {
        int mn = 0;
        int sum = 0;

        for (int val : nums) {
            sum += val;
            mn = Math.min(mn, sum);
        }

        return 1 - mn;
    }
}
