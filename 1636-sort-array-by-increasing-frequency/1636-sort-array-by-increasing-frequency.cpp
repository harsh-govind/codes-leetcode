class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto &val:nums)
        {
            m[val]++;
        }

        priority_queue<pair<int, int>> minHeap;

        for(auto &val:m)
        {
            minHeap.push({-val.second, val.first});
        }

        vector<int> ans;

        while(minHeap.size()>0)
        {
            for(int i=0; i<-minHeap.top().first; i++)
            {
                ans.push_back(minHeap.top().second);
            }
            minHeap.pop();
        }

        return ans;
    }
};