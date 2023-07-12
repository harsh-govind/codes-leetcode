class Solution
{
    public:

    bool rotateString(string a, string b)
    {
        if (a == b or a.size() == 0 or b.size() == 0) return true;
        if (a.size() != b.size()) return false;

        int n = a.size();
        string temp=a+a;

        for (int i = 0; i < n; i++)
        {
            int j;
            for(j=0; j<n; j++)
            {
                if(b[j]!=temp[i+j]) break;
            }
            if(j==n) return true;
        }
        return false;
    }
};