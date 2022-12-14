class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        vector<vector<int>> store;
        vector<int> temp;
        for(int i=0;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
        }
        store.push_back(temp);
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            vector<int> k;
            for(int j=0; j<n-i;j++)
            {
                k.push_back((store[i-1][j]+store[i-1][j+1])%10);
            }
            store.push_back(k);
        }
    
        return store[n-1][0];
    }
};