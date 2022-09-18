class Solution {
public:
    int trap(vector<int> &v)
{
    int i, n = v.size(), ans = 0;
    vector<int> left(n), right(n);
    left[0]=v[0];
    right[n - 1] = v[n - 1];
    for (i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], v[i]);
    }
    for (i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], v[i]);
    }
    for (i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - v[i];
    }
    return ans;
}
};

static bool _foo = ios::sync_with_stdio(false);
static ostream *_bar = cin.tie(NULL);