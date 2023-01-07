class Solution
{
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
        {
            int have = accumulate(gas.begin(), gas.end(), 0), need = accumulate(cost.begin(), cost.end(), 0);

            if (have < need)
            {
                return -1;
            }

            int ans = 0, temp = 0;

            for (int i = 0; i < gas.size(); i++)
            {
                temp += (gas[i] - cost[i]);
                if (temp < 0)
                {
                    ans = i + 1;
                    temp = 0;
                }
            }
            return ans;
        }
};