class Solution {
public:
    using VT = pair<vector<string>,unordered_map<string,int>>;
    VT gNodes(int n, int k) {
        if (n==1) return VT({""},{{"",0}});
        VT ns;
        auto prev = gNodes(n-1,k).first;
        for (auto s: prev) {
            s += " ";
            for (int i=0; i<k; ++i) {
                s.back() = '0'+i;
                ns.second[s] = ns.first.size();
                ns.first.push_back(s);
            }
        }
        return ns;
    }
    string crackSafe(int n, int k) {
        if (n<2) return string("0123456789").substr(0,k);
        auto [ns,hn] = gNodes(n,k);
        auto N = ns.size();
        vector<pair<int,int>> arcs;
        for (auto [s,x]: hn) {
            auto t = s.substr(1,-1)+" "; 
            for (int i=0; i<k; ++i) {
                t.back() = '0'+i;
                arcs.emplace_back(x,hn[t]);
            }
        }
        vector<vector<int>> unused(N,[k](){vector<int> t(k); iota(t.begin(),t.end(),0); return t;}());
        string code;
        int ss = 0;
        while (ss>=0) {
            auto cm(0);
            code += ns[ss];
            bool cont(true);
            while (cont) {
                auto nx = '0'+unused[ss].back();
                unused[ss].pop_back();
                code += nx;
                ss = hn[code.substr(code.length()-n+1,n-1)];
                cont = !unused[ss].empty();
            }
            ss = -1;
        }
        return code;
    }
};