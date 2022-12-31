#include <bit>

class Solution {
public:
    static int dp(int n, int k, int mask, const vector<int>& deps, vector<int>& dpMem) {
        if (mask + 1 == 1 << n) {
            return 0;
        }

        if (dpMem[mask] != -1) {
            return dpMem[mask];
        }

        int possible = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask & deps[i]) == deps[i]) {
                if ((mask & (1 << i)) == 0) {
                    possible |= 1 << i;
                }
            }
        }

        int best = 123456789;
        for (int daymask = possible; daymask > 0; daymask = ((daymask - 1) & possible)) {
            if (__popcount(daymask) <= k) {
                best = min(best, 1 + dp(n, k, mask | daymask, deps, dpMem));
            }
        }
        dpMem[mask] = best;
        return best;
    }

    int minNumberOfSemesters(int n, const vector<vector<int>>& relations, int k) {
        vector<int> deps(n);
        for (const auto& v: relations) {
            deps[v[1] - 1] |= 1 << (v[0] - 1);
        }
        vector<int> dpMem(1 << n, -1);
        return dp(n, k, 0, deps, dpMem);
    }
};
