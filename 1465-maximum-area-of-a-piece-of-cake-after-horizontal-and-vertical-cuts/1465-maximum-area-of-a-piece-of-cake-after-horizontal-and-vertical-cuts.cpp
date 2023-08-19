class Solution {
public:
    #define mod 1000000007
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int m=horizontalCuts.size(), n=verticalCuts.size();
        int hh=horizontalCuts[0], ww=verticalCuts[0];

        
        for(int i=1; i<m; i++)
        {
            hh=max(horizontalCuts[i]-horizontalCuts[i-1], hh);
        }
        for(int i=1; i<n; i++)
        {
            ww=max(verticalCuts[i]-verticalCuts[i-1], ww);
        }
        
        hh=max(hh, h-horizontalCuts.back());
        ww=max(ww, w-verticalCuts.back());
        
        return (1ll * hh * ww)%mod;
    }
};