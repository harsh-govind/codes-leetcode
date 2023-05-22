class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto &val:nums)
        {
            m[val]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(auto &val:m)
        {
            minHeap.push({val.second, val.first});
            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        vector<int> ans;

        while(minHeap.size()>0)
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};