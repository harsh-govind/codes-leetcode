class Solution{
   struct Edge{
      int v, w, sw, rev;
      constexpr Edge(int v, int w, int sw, int rev) noexcept: v(v), w(w), sw(sw), rev(rev){}
   };
public:
   int maximumRequests(int n, vector<vector<int>> &req) const{
      vector<vector<Edge>> g(n);
      int ans = 0;
      for(auto const &e: req){
         int u = e[0], v = e[1];
         if(u == v){
            ++ans; continue;
         }
         g[u].emplace_back(v, 1, 1, g[v].size());
         g[v].emplace_back(u, -1, 0, g[u].size()-1);
      }
      while(1){
         vector<int> d(n), pv(n), pe(n), cnt(n);
         queue<int> bf;
         for(int i=0; i<n; ++i){
            bf.push(i);
         }
         vector<bool> inq(n, true);
         int ncv = -1;
         while(!bf.empty()){
            int u = bf.front(); bf.pop(); inq[u] = false;
            for(size_t i=0; i<g[u].size(); ++i){
               auto [v, w, sw, _] = g[u][i];
               if(!sw || d[v]>=d[u]+w) continue;
               d[v] = d[u]+w;
               pv[v] = u; pe[v] = i;
               if(!inq[v]){
                  if(++cnt[v] == n){
                     ncv = v;
                     goto after_bf;
                  }
                  bf.push(v); inq[v] = true;
               }
            }
         }
         after_bf:
         if(ncv == -1) break;
         vector<bool> vis(n);
         for(; !vis[ncv]; ncv=pv[ncv]){
            vis[ncv] = true;
         }
         int u = ncv;
         do{
            int p = pv[u], i = pe[u];
            ans += g[p][i].w;
            g[p][i].sw = 0;
            g[u][g[p][i].rev].sw = 1;
            u = p;
         }while(u != ncv);
      }
      return ans;
   }
};
