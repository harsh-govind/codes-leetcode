class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxHeap;

        for(auto &val:arr)
        {
            maxHeap.push({abs(val-x), val});
            if(maxHeap.size()>k)
            {
                maxHeap.pop();
            }
        }

        vector<int> ans;

        while(maxHeap.size()>0)
        {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream *_bar = cin.tie(NULL);