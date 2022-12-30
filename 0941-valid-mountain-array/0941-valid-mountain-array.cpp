class Solution
{
    public:
        bool validMountainArray(vector<int> &arr)
        {
            int n = arr.size();
            int idx = 0;
            for (int i = 0; i < n - 1; i++)
            {
                if (arr[i + 1] < arr[i])
                {
                    idx = i;
                    break;
                }
                else if (arr[i] == arr[i + 1])
                {
                    return false;
                }
            }
            cout << idx << " " << arr[idx] << " ";
            for (int i = n - 1; i >= 1; i--)
            {
                if (arr[i - 1] < arr[i])
                {
                    return idx == i;
                }
                else if(arr[i-1]==arr[i])
                {
                    return false;
                }
            }
            return false;
        }
};