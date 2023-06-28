class NumArray
{
    public:
        vector<int> sum;
    NumArray(vector<int> &nums)
    {
        int s = 0;
        for (auto &val: nums)
        {
            sum.push_back(s = s + val);
            cout<<s<<" ";
        }
        cout<<endl;
        for (auto &val: sum)
        {
            cout<<val<<" ";
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0) return sum[right];

        return sum[right] - sum[left - 1];
    }
};

/**
 *Your NumArray object will be instantiated and called as such:
 *NumArray* obj = new NumArray(nums);
 *int param_1 = obj->sumRange(left,right);
 */