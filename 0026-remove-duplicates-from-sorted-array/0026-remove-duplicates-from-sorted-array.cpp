class Solution {
public:
int removeDuplicates(vector<int> &v)
{
    set<int> s;
    for (auto &val : v)
    {
        s.insert(val);
    }
    int i = 0;
    for (auto &val : s)
    {
        v[i++] = val;
    }
    return s.size();
}
};