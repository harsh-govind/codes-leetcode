class Solution
{
    public:
        vector<vector < int>> insert(vector<vector < int>> &intervals, vector< int > &newInterval)
        {
            vector<vector < int>> ans;
            for (auto &it: intervals)
            {
                if (it[1] >= newInterval[0] and it[0] <= newInterval[1])
                {
                    newInterval[0] = min(it[0], newInterval[0]);
                    newInterval[1] = max(it[1], newInterval[1]);
                }
                else
                {
                    if (it[0] > newInterval[0])
                        swap(it, newInterval);
                    ans.push_back(it);
                }
            }
            ans.push_back(newInterval);
            return ans;
        }
};