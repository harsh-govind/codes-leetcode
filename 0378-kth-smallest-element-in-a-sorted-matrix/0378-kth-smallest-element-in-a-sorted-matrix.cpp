class Solution
{
    public:
        int kthSmallest(vector<vector < int>> &matrix, int k)
        {
            priority_queue<int> p;
            for (auto &r: matrix)
            {
                for (auto &val: r)
                {
                    p.push(val);
                    if (p.size() > k)
                    {
                        p.pop();
                    }
                }
            }
            return p.top();
        }
};