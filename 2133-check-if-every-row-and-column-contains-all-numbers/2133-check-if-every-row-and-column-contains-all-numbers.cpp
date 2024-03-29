class Solution
{
    public:
        Solution()
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        }
    bool checkValid(vector<vector < int>> &m)
    {
       	//row
        int n = m.size();
        cout << "row sums\n";
        for (int i = 0; i < n; i++)
        {
            int sumr = 0, sumc = 0;
            unordered_set<int> sr, sc;
            for (int j = 0; j < n; j++)
            {
                sumr += m[i][j];
                sumc += m[j][i];
                sr.insert(m[i][j]);
                sc.insert(m[j][i]);
            }

            if ((sumr != ((n *(n + 1)) / 2)) or(sumc != ((n *(n + 1)) / 2)) or sr.size() != n or sc.size() != n)
            {
                return false;
            }
        }

        return true;
    }
};