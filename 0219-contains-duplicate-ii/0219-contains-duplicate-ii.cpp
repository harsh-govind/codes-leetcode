class Solution
{
    public:
        bool containsNearbyDuplicate(vector<int> &nums, int k)
        {
            unordered_map<int, vector < int>> mp;

            for (int i = 0; i < nums.size(); i++)
            {
                int val = nums[i];
                if (mp.find(val) != mp.end())
                {
                    vector<int> &temp = mp[val];
                    for (int j = 0; j < temp.size(); j++)
                    {
                        if ((abs(temp[j] - i)) <= k)
                            return true;
                    }
                }

                mp[val].push_back(i);
            }

            return false;
        }
};