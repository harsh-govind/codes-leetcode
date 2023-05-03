class Solution
{
    public:
        vector<vector < int>> findDifference(vector<int> &nums1, vector<int> &nums2)
        {
            unordered_set<int> first, second;

            for (auto &val: nums1)
            {
                first.insert(val);
            }

            for (auto &val: nums2)
            {
                second.insert(val);
            }


            vector<vector < int>> ans;
            vector<int> temp1, temp2;
            for (auto &val: first)
            {
                if(second.find(val)==second.end())
                {
                    temp1.push_back(val);
                }
            }
            for (auto &val: second)
            {
                if(first.find(val)==first.end())
                {
                    temp2.push_back(val);
                }
            }

            ans.push_back(temp1);
            ans.push_back(temp2);

            return ans;
        }
};