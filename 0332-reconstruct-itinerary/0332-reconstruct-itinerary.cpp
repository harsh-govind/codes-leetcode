class Solution {
public:
    vector<string> ans;
    stack<string> s;
    map<string, queue<string>> adj;
    
    void hierthing(string &src){
        // pushing to stack
        s.push(src);
        
        // recursing till outdegree is 0
        while (!adj[src].empty()){
            string v = adj[src].front();
            adj[src].pop();
            hierthing(v);
        }
        
        // popping from stack and adding to the answer
        ans.push_back(s.top());
        s.pop();
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // sorting to ensure lexical order
        sort(tickets.begin(), tickets.end());
        
        for (auto trip: tickets){
            // pushing destination to a queue
            adj[trip[0]].push(trip[1]);
        }
        
        string s = "JFK";
        hierthing(s);
        
        // reversed answer
        reverse(ans.begin(), ans.end());
        return ans;
    }
};