class Solution
{
    public:
        vector<int> plusOne(vector<int> &v)
{
    int n = v.size();
    // if (v[n - 1] < 9)
    // {
    //     v[n - 1]++;
    //     return v;
    // }
    // else
    // if (v[n - 1] == 9 and n == 1)
    // {
    //     v.clear();
    //     v.push_back(1);
    //     v.push_back(0);
    //     return v;
    // }
    // else
    // {
    int i = n - 1;
    while (i > -1)
    {
        if (v[i] < 9)
        {
            v[i]++;
            return v;
        }
        else
        {
            v[i] = 0;
            i--;
        }
    }
    // }
    v.insert(v.begin(), 1);
    return v;
}
};