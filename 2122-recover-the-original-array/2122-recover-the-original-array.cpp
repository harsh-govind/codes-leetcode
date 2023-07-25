class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if((nums[i] - nums[0])%2 == 0 && (nums[i] - nums[0]) > 0)
            {
                int k = nums[i]-nums[0];
                queue<int> q;
                q.push(nums[0]);
                vector<int> ans;
                for(int i=1;i<nums.size();i++)
                {
                    if(!q.empty() && nums[i] - k == q.front())
                    {
                        ans.push_back(nums[i] - k/2);
                        q.pop();
                    }
                    else
                    {
                        q.push(nums[i]);
                    }
                }
                if(q.empty())
                {
                    return ans;
                }
            }
        }
        return {};
    }
};