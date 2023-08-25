class Solution
{
public:
    unordered_map<string, bool> mp;
    bool solve(int l1, int l2, int l3, string s1, string s2, string s3, int p1, int p2, int p3)
    {
        if (l1 == p1 and l2 == p2 and l3 == p3)
            return true;

        string key = to_string(p1) + '&' + to_string(p2) + '&' + to_string(p3);

        if (mp.count(key))
            return mp[key];

        bool flag = false;

        if (p1 < l1 and s1[p1] == s3[p3])
            flag |= solve(l1, l2, l3, s1, s2, s3, p1 + 1, p2, p3 + 1);

        if (p2 < l2 and s2[p2] == s3[p3])
            flag |= solve(l1, l2, l3, s1, s2, s3, p1, p2 + 1, p3 + 1);

        return mp[key] = flag;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();

        mp.clear();

        if (l1 + l2 != l3)
            return false;

        return solve(l1, l2, l3, s1, s2, s3, 0, 0, 0);
    }
};