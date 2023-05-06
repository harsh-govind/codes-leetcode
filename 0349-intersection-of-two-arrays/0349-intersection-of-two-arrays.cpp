class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a, b;
        vector<int> ans;
        
        for(auto &val:nums1)
        {
            a.insert(val);
        }
        
        for(auto &val:nums2)
        {
            if(a.find(val)!=a.end() and b.find(val)==b.end())
            {
                ans.push_back(val);
                b.insert(val);
            }
        }            
        return ans;
    }
};