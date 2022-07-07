class Solution
{
    public:
        vector<int> plusOne(vector<int> &v)
        {
            int n = v.size();
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
            v.insert(v.begin(), 1);
            return v;
        }
};