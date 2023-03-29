class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int ans = 0;
        int index = 0;
        int sum = 0;
        while(index<satisfaction.size() && (ans)<=(ans + sum + satisfaction[index]))
        {
            sum += satisfaction[index];
            ans = max(ans,ans+sum);
            index++;
        }
        return ans;
    }
};