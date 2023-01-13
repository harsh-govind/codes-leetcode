class Solution
{
    public:
        vector<vector < int>> graph;
    int result {};

    int dfs(int u, string &s)
    {
        int first = 0, second = 0;
        for (auto it: graph[u])
        {
            if (s[it] != s[u])
            {
                int temp = 1 + dfs(it, s);
                if (temp > first)
                {
                    second = first;
                    first = temp;
                }
                else if (temp >= second)
                {
                    second = temp;
                }
            }
            else
            {
                result = max(result, dfs(it, s));
            }
        }

        result = max(result, first + second);
        return first;
    }

    int longestPath(vector<int> &parent, string s)
    {
        int n = parent.size();
        graph = vector<vector < int>> (n);
        for (int i = 0; i < n; i++)
        {
            if (parent[i] != -1)
            {
               	// graph[i].push_back(parent[i]);
                graph[parent[i]].push_back(i);
            }
        }

       	// vector<bool> visited(n, false);
       	// cout<<"Hello"<<endl;
        result = max(result, dfs(0, s));
        return result + 1;
    }
};