class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), minOper = n + 1, prefixSum = 0;
        unordered_map<int, int> mp;
        for(int i = 0 ; i < n ; i++){
            prefixSum += nums[i];
            if(prefixSum == x)
                minOper = i + 1;
            if(prefixSum > x)
                break;
            mp[prefixSum] = i + 1;
        }
        int suffixSum = 0;
        for(int i = n - 1 ; i >= 0 ; i--){
            suffixSum += nums[i];
            if(suffixSum == x)
                minOper = min(minOper, n - i);
            else if(suffixSum < x){
                if(mp.find(x - suffixSum) != mp.end())
                    minOper = min(minOper, n - i + mp[x - suffixSum]);
            }
            else
                break;
        }
        return (minOper != n + 1) ? minOper : -1;
    }
};