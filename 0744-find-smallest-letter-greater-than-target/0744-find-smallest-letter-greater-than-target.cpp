class Solution
{
    public:
        char nextGreatestLetter(vector<char> &letters, char target)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            int low = 0, high = letters.size() - 1;

            while (low < high)
            {
                int mid = low + (high - low) / 2;

                if (letters[mid] == target)
                {
                    low = mid + 1;
                }
                else if (letters[mid] > target)
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }

            return letters[low] > target ? letters[low] : letters[0];
        }
};