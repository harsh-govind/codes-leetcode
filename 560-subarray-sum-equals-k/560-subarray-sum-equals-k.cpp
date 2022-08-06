class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0, currSum=0;
        unordered_map<int, int> m;
        m[0]++;
        for(int i=0;i<nums.size();i++)
        {
            currSum+=nums[i];
            
            if(m.find(currSum-k)!=m.end())
            {
                ans+=m[currSum-k];
            }
            
            m[currSum]++;
        }
        return ans;
    }
};