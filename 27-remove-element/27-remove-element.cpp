//using o(1) space
class Solution {
public:
    int removeElement(vector<int> &v, int k) // space o(1)
{
    int ans = 0, n = v.size();
    for (auto &val : v)
    {
        if (val == k)
        {
            ans++;
        }
    }
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (v[j] != k)
        {
            v[i++] = v[j];
        }
    }
    return n - ans;
}
};