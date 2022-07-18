class Solution
{
    public:
        static bool compa(string &a, string &b)
        {
            return a + b > b + a;
        }
    string largestNumber(vector<int> &nums)
    {
        vector<string> arr;
        for (auto &val: nums)
        {
            stringstream ss;
            ss << val;
            string s;
            ss >> s;
            arr.push_back(s);
        }
        sort(arr.begin(), arr.end(), compa);
        string ans;
        for (auto &val: arr)
        {
            ans += val;
        }
        int cnt = count(ans.begin(), ans.end(), '0');
        if (cnt == ans.length())
            return "0";
        return ans;
    }
};