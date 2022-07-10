class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        for(auto &val:nums)
        {
            int mx=0;
            for(auto &val2:nums)
            {
                if(val2<val)
                {
                    mx++;
                }
            }
            ans.push_back(mx);
        }
        return ans;
    }
};