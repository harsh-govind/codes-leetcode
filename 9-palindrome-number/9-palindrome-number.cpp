class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        long long temp = x, ans=0;
        while(temp>0)
        {
            ans = ans*10 + temp%10;
            temp/=10;
        }
        if(ans==x)
        {
            return true;
        }
        return false;
    }
};