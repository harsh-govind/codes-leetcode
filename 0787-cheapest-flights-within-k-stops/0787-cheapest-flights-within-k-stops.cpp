class Solution
{
    public:
        int findCheapestPrice(int n, vector<vector < int>> &flights, int src, int dst, int k)
        {
            vector<vector<pair<int, int>>> g(n);
            vector<int> costs(n, INT_MAX);
            int answer = INT_MAX;

            for (auto &f: flights) g[f[0]].push_back({ f[1],
                f[2] });	//current = {neigbour, cost to it}

            queue<tuple<int, int, int>> q;
            q.push({ 0,
                src,
                -1 });	//total cost, to, tmp k
            while (!q.empty())
            {
                auto[tc, tt, tk] = q.front();
                q.pop();
                if (tt == dst)
                {
                    answer = min(tc, answer);
                    continue;
                }
                if (tk++ == k || costs[tt] < tc) continue;
                costs[tt] = tc;

                for (auto &[n, c]: g[tt])	// &[neigbour, cost to it] 
                    if (tc + c < costs[n]) q.push({ tc + c,
                        n,
                        tk });
            }

            return answer == INT_MAX ? -1 : answer;
        }
};