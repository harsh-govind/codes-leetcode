class Solution {
public:
    typedef pair<double,int> pii;
    vector<vector<pair<int,double>>> buildGraph(int n,vector<vector<int>>& roads,vector<double>&prob){
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0;i<roads.size();++i){
            graph[roads[i][0]].push_back({roads[i][1],prob[i]});
            graph[roads[i][1]].push_back({roads[i][0],prob[i]});
        }    
        return graph;
    }
    
    double maxProbability(int n,vector<vector<int>>& edges,vector<double>& prob,int s,int e) {
        vector<vector<pair<int,double>>> g = buildGraph(n,edges,prob);
        vector<double> probTo(n,0);
        priority_queue<pii> q;
        q.push({1,s});
        probTo[s] = 1;
        while(q.size()>0){
            int curr = q.top().second;
            q.pop();
            for(auto it : g[curr]){
                int next = it.first;
                double nextProb = it.second;
                if(probTo[next] < probTo[curr]*nextProb){
                    probTo[next] = probTo[curr]*nextProb;
                    q.push({probTo[next],next});
                }
            }
        }
        return probTo[e];
    }
};