class Solution {
public:
int check(int l, vector<int>& arr1 ,vector<int>& arr2, vector <unordered_map<int,int> >& dp,int curr)
{
          if (curr == arr1.size())
            return 0;
          if (dp[curr].find(l) != dp[curr].end())
            return dp[curr][l];
          int ex,mx;
          if (arr1[curr] > l)    
            ex = check(arr1[curr], arr1, arr2, dp,curr+1);
          else
            ex = INT_MAX;
          int ans = upper_bound(arr2.begin(),arr2.end(), l) - arr2.begin();
           if (ans == arr2.size())
             mx = INT_MAX;
           else
            mx = check(arr2[ans], arr1, arr2, dp,curr+1);
           if (mx == INT_MAX)
            dp[curr][l] = ex;
           else
            dp[curr][l] = min(ex,mx+1);

    return dp[curr][l];
}

public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {

           sort(arr2.begin(), arr2.end());
           vector <unordered_map<int,int> > dp(2001);  
           int v = check(INT_MIN, arr1, arr2, dp,0);
            if (v == INT_MAX)
                return -1;
        return v;
    }
};