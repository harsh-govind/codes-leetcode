class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        
        for(int i=0; i<points.size(); i++)
        {
            int key = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            maxHeap.push({key, {points[i][0], points[i][1]}});
            
            if(maxHeap.size()>k)
            {
                maxHeap.pop();
            }
        }
        
        vector<vector<int>> ans;
        
        while(maxHeap.size()>0)
        {
            vector<int> temp;
            temp.push_back(maxHeap.top().second.first);
            temp.push_back(maxHeap.top().second.second);
            ans.push_back(temp);
            maxHeap.pop();
        }
        return ans;
    }
};