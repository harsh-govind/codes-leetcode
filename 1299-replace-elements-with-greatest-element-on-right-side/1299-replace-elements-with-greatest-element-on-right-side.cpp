class Solution
{
    public:
        vector<int> replaceElements(vector<int> &a)
        {
            int maxElement = a[a.size() - 1];
            for (int i = a.size()-1; i>=0; i--)
            {
                int temp = a[i];
                a[i] = maxElement;
                maxElement=max(maxElement, temp);
            }

            a[a.size() - 1] = -1;

            return a;
        }
};