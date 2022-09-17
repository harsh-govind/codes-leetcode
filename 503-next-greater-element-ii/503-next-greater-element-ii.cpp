class Solution
{
    public:
        vector<int> nextGreaterElements(vector<int> &nums)
        {
            vector<int> ans;
            stack<int> s;

            for (int i= (2*nums.size())-1; i >=0; i--) {
                while(!s.empty() and s.top()<=nums[i%nums.size()])
                {
                    s.pop();
                }
                
                if(i<nums.size())
                {
                    if(!s.empty())
                    {
                        ans.push_back(s.top());
                    }
                    else
                    {
                        ans.push_back(-1);
                    }
                }
                s.push(nums[i%nums.size()]);
            }

            reverse(ans.begin(), ans.end());
            return ans;
        }
};