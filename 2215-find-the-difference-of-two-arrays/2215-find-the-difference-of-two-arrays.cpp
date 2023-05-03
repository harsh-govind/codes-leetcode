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

            unordered_set<int> one, two;

            for (auto &val: nums1)
            {
                if (second.find(val) == second.end())
                {
                    one.insert(val);
                }
            }
            for (auto &val: nums2)
            {
                if (first.find(val) == first.end())
                {
                    two.insert(val);
                }
            }

            vector<vector < int>> ans;
            vector<int> temp1, temp2;
            for (auto &val: one)
            {
                temp1.push_back(val);
            }
            for (auto &val: two)
            {
                temp2.push_back(val);
            }

            ans.push_back(temp1);
            ans.push_back(temp2);

            return ans;
        }
};