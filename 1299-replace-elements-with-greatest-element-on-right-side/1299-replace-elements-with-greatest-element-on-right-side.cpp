class Solution
{
    public:
        vector<int> replaceElements(vector<int> &a)
        {
            for (int i = 0; i < a.size() - 1; i++)
            {
                int temp = INT_MIN;
                for (int j = i + 1; j < a.size(); j++)
                {
                    temp = max(temp, a[j]);
                }

                a[i] = temp;
            }

            a[a.size() - 1] = -1;

            return a;
        }
};