class Solution
{
    public:
        void nextPermutation(vector<int> &nums)
        {
            int beforeTop = -1, n = nums.size();
            for (int i = n - 1; i > 0; i--)
            {
                if (nums[i - 1] < nums[i])
                {
                    beforeTop = i-1;
                    break;
                }
            }
            cout<<beforeTop<<endl;
            if (beforeTop == -1)
            {
                reverse(nums.begin(), nums.end());
                return;
            }

            for (int i = n - 1; i > beforeTop; i--)
            {
                if (nums[i] > nums[beforeTop])
                {
                    swap(nums[beforeTop], nums[i]);
                    break;
                }
            }

            reverse(nums.begin() + beforeTop+1, nums.end());
        }
};