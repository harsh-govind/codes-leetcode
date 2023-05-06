class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int, vector<int>, greater<int> > pq;
        
        for(auto &val:nums)
        {
            pq.push(val);
            cout<<pq.top()<<" ";
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        
        
        
        return pq.top();
    }
};