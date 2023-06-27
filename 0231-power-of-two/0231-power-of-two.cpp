class Solution
{
    public:
        bool isPowerOfTwo(int n)
        {
            return n >= 1 and(n &(n - 1)) == 0;
        }
};