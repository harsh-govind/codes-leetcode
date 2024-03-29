class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto &val:nums)
        {
            minHeap.push(val);
            if(minHeap.size()>k)
            {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream *_bar = cin.tie(NULL);