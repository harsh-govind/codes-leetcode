class Solution {
public:
    int minBitFlips(int a, int b) {
        int ans=0;
        while(a or b)
        {
            ans+=(a&1) ^ (b&1);
            a=a>>1;
            b=b>>1;
        }
        return ans;
    }
};