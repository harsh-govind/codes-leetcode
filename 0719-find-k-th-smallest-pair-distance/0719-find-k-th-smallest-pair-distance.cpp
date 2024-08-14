class Solution {
public:
    // <!-- function to find all the possible pairs with given dist -->
    int findPairs(int dist, vector<int>& nums){
        // <!-- use two pointers (sliding window) tech to calculate all the pairs in an array that is <= given dist> -->
        int n = nums.size();
        int l = 0;
        int r = 0;
        int p = 0;
        for(int r = 0; r < n; r++){
            while(nums[r] - nums[l] > dist) l++;
            p += r - l;
        }
        return p;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        // <!-- identify the range within which differences will lie -->
        int left = 0;
        // <!-- as said in the intuition about max difference -->
        int right = *max_element(nums.begin(), nums.end());

        // <!-- apply binary search to avoid checking for all differences between left to right -->
        while(left < right){
            int mid = (left + right)/2;
            int pairs = findPairs(mid, nums);
            // <!-- if pairs are greater than k, reduce the diff i.e shrink the search space by moving right to mid -->
            if(pairs >= k){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }   

        // <!--at last left and right will be on same pos, you can return either of them  -->
        return left;
    }
};