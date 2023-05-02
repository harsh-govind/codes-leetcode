class Solution
{
    public:
        int arraySign(vector<int> &nums)
        {
            int neg = 0;
            for (auto &val: nums)
            {
                if (val < 0)
                {
                    neg++;
                }
                cout<<val<<" ";
                if (val == 0)
                {
                    return 0;
                }
            }

            if(neg%2==0)
            {
                return 1;
            }
            return -1;
        }
};