class Solution
{
    public:
        int minStartValue(vector<int> &arr)
        {
            int minn, sum;
            minn = sum = 0;
            for (int &v: arr)
            {
                sum += v;
                if (sum < minn)
                {
                    minn = sum;
                }
            }
            return 1 - minn;
        }
};