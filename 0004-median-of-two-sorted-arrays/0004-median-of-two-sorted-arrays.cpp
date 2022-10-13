class Solution
{
    public:
        double findMedianSortedArrays(vector<int> &a, vector<int> &b)
        {
            vector<int> c;

            int m = a.size(), n = b.size();
            int i = 0, j = 0;

            while (i < m and j < n)
            {
                if (a[i] < b[j])
                {
                    c.push_back(a[i++]);
                }
                else if (a[i] > b[j])
                {
                    c.push_back(b[j++]);
                }
                else
                {
                    c.push_back(a[i++]);
                    c.push_back(b[j++]);
                }
            }

            for (; i < m; i++)
            {
                c.push_back(a[i]);
            }
            for (; j < n; j++)
            {
                c.push_back(b[j]);
            }
            
            
            for(int i=0; i<m+n;i++)
            {
                cout<<c[i]<<endl;
            }
            cout<<endl;

            if (c.size() % 2 == 0)
            {
                n = m + n;
                cout << c[n / 2] << " " << c[(n / 2) - 1] << endl;
                return (double)(c[(n - 1) / 2] + c[n / 2]) / 2.0;
            }
            else
            {
                n = m + n;
                cout << c[n / 2] << endl;

                return c[n / 2];
            }
        }
};