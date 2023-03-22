
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> g;
        
        for (auto road : roads) {
            int u = road[0];
            int v = road[1];
            int d = road[2];
            g[u].push_back({v, d});
            g[v].push_back({u, d});
        }
        
        unordered_set<int> visited;
        int ans = INT_MAX;
        queue<int> q;
        q.push(1);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visited.insert(u);
            for (auto p : g[u]) {
                if (visited.count(p.first)) {
                    continue;
                }
                ans = min(ans, p.second);
                q.push(p.first);
            }
        }
        
        return ans;
    }
};