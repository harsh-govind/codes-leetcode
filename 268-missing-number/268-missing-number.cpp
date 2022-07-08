class Solution {
public:
    int missingNumber(vector<int>& v) {
    long long actual2, given2, actual, given, n = v.size();
    actual2 = given2 = actual = given = 0;
    actual = (n * (n + 1)) / 2;
    actual2 = (n * (n + 1) * (2 * n + 1)) / 6;
    for (auto &val : v)
    {
        given += (long long)val;
        given2 += ((long long)val * (long long)val);
    }
    long long a = actual - given;
        if(a==0)
            return 0;
    long long k = (actual2 - given2) / a;
    long long m = (k + a) / 2;
   return m;
    }
};