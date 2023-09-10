class Solution
{
    public:
        int solve(vector<int> &nums, int maxNum)
        {
            
            int firstIdx = -1, lastIdx = -1;

            for (int i = 0; i < nums.size(); i++)
            {
                if (firstIdx == -1 and nums[i] == maxNum)
                {
                    firstIdx = i;
                }

                if (lastIdx == -1 and nums[nums.size() - i - 1] == maxNum)
                {
                    lastIdx = nums.size() - i - 1;
                }
            }

            return lastIdx - firstIdx + 1;
        }
        int findShortestSubArray(vector<int> &nums)
        {
            unordered_map<int, int> m;

            for (auto &val: nums) m[val]++;

            int maxFreq = INT_MIN, maxNum = INT_MIN;

            for (auto &val: m)
            {
                if (val.second > maxFreq)
                {
                    maxNum = val.first;
                    maxFreq = val.second;
                }
            }
            
            vector<int> maxFreqNums;
            
            for(auto &val:m)
            {
                if(val.second==maxFreq)
                {
                    maxFreqNums.push_back(val.first);
                }
            }
            
            
            int ans=INT_MAX;
            
            for(auto &val:maxFreqNums)
            {
                ans=min(ans, solve(nums, val));
            }
            
            return ans;

        }
};