class Solution
{
    public:
        int firstMissingPositive(vector<int> &nums)
        {

            map<int, int> m;

            for (int i = 1; i <= nums.size(); i++)
            {
                m[i] = 0;
            }

            for (auto &val: nums)
            {
                if (val > 0)
                {
                    m[val]++;
                }
            }

            for (auto &val: m)
            {
                cout << val.first << " " << val.second << endl;
                if (val.second == 0)
                    return val.first;
            }

            auto last = m.end();
            last--;
            return last->first + 1;
        }
};