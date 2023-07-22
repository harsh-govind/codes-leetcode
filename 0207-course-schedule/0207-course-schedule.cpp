class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& prerequisites) {
        vector<int> adj[v];
	    for(int i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
	    
	    vector<int> indegree(v, 0);
	    
	    for(int i=0; i<v; i++)
	    {
	        for(auto &it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0; i<v; i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    vector<int> topo;
	    while(!q.empty())
	    {
	        int front=q.front();
	        q.pop();
	        topo.push_back(front);
	        
	        for(auto &it:adj[front])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            {
	                q.push(it);
	            }
	        }
	    }
	    
	    return topo.size()==v;
    }
};