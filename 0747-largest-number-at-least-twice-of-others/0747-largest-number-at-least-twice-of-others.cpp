class Solution
{
    public:
        int dominantIndex(vector<int> &nums)
        {
            int maxEle = INT_MIN, maxEleIndex = -1;
            for (int i = 0; i < nums.size(); i++)
            {
                if (maxEle < nums[i])
                {
                    maxEle = nums[i];
                    maxEleIndex = i;
                }
            }
            cout << maxEleIndex << " " << maxEle << endl;
            for (int i = 0; i < nums.size(); i++)
            {
                if (i != maxEleIndex and (nums[i] *2) > maxEle)
                {
                    return -1;
                }
            }

            return maxEleIndex;
        }
};