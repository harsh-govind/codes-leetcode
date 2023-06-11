class Solution
{
    private:
        void solve(string digits, string current, int idx, vector<string> &ans, string check[])
        {
            if (idx >= digits.size())
            {
                ans.push_back(current);
                return;
            }

            string m = check[digits[idx] - '0'];
            for (int i = 0; i < m.size(); i++)
            {
                current.push_back(m[i]);
                solve(digits, current, idx + 1, ans, check);
                current.pop_back();
            }
        }
    public:
        vector<string> letterCombinations(string digits)
        {
            string check[10] = { "",
                "",
                "abc",
                "def",
                "ghi",
                "jkl",
                "mno",
                "pqrs",
                "tuv",
                "wxyz" };
            vector<string> ans;
            if(digits.size()==0) return ans;
            string current;
            solve(digits, current, 0, ans, check);
            return ans;
        }
};