class Solution
{
    public:
        int check(vector<int> a, int n)
        {
            while (--n > 0 && a[n] == a[0]);
            return n != 0;
        }
    int MAH(vector<int> &h)
    {

        if (!check(h, h.size()))
        {
            return h.size() *h[0];
        }
        vector<int> sl;
        stack<pair<int, int>> s;
        int n = h.size();
        for (int i = 0; i < n; i++)
        {
            if (s.empty())
            {
                sl.push_back(-1);
            }
            else if (s.size() > 0 and s.top().first < h[i])
            {
                sl.push_back(s.top().second);
            }
            else if (s.size() > 0 and s.top().first >= h[i])
            {
                while (s.size() > 0 and s.top().first >= h[i])
                    s.pop();

                if (s.size() == 00)
                {
                    sl.push_back(-1);
                }
                else
                {
                    sl.push_back(s.top().second);
                }
            }
            s.push({ h[i],
                i });
        }

        for (auto &val: sl)
        {
            cout << val << " ";
        }
        cout << endl;

        stack<pair<int, int>> ss;
        vector<int> sr(n);

        for (int i = n - 1; i >= 0; i--)
        {
            if (ss.empty())
            {
                sr[i] = n;
            }
            else if (ss.size() > 0 and ss.top().first < h[i])
            {
                sr[i] = ss.top().second;
            }
            else if (ss.size() > 0 and ss.top().first >= h[i])
            {
                while (ss.size() > 0 and ss.top().first >= h[i])
                    ss.pop();

                if (ss.size() == 00)
                {
                    sr[i] = n;
                }
                else
                {
                    sr[i] = ss.top().second;
                }
            }
            ss.push({ h[i],
                i });
        }

        for (auto &val: sr)
        {
            cout << val << " ";
        }
        cout << endl;
        int maxWidth = -1;
        for (int i = 0; i < n; i++)
        {
            maxWidth = max(maxWidth, h[i] *(sr[i] - sl[i] - 1));
        }
        return maxWidth;
    }
    int maximalRectangle(vector<vector < char>> &matrix)
    {
        vector<int> v;

        for (int i = 0; i < matrix[0].size(); i++)
        {
            if (matrix[0][i] == '0')
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(1);
            }
        }

        int ans = MAH(v);

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == '0')
                {
                    v[j] = 0;
                }
                else
                {
                    v[j] = v[j] + 1;
                }
            }

            ans = max(ans, MAH(v));
        }

        return ans;
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream *_bar = cin.tie(NULL);