class Solution
{
    public:
        int vis[100005];
    vector<int> adj[100005];

    void dfs(int node, long long &ct)
    {
        ct++;
        vis[node] = 1;

        for (auto it: adj[node])
        {
            if (!vis[it])
            {
                dfs(it, ct);
            }
        }
    }

    long long countPairs(int n, vector<vector < int>> &v)
    {
        int i;
        for (i = 0; i < v.size(); i++)
        {
            adj[v[i][0]].push_back(v[i][1]);
            adj[v[i][1]].push_back(v[i][0]);
        }

        vector < long long > ans;

        for (i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                long long ct = 0;
                dfs(i, ct);
                ans.push_back(ct);
            }
        }

        sort(ans.begin(), ans.end());
        long long sum = 0;

        for (i = 0; i < ans.size(); i++)
        {
            sum += ans[i];
        }

        long long fin = 0;

        for (i = 0; i < ans.size(); i++)
        {
            sum -= ans[i];
            fin += (sum *ans[i]);
        }

        return fin;
    }
};