class Solution {
public:
    int divide(int n, int factor)
    {
        while(n%factor==0) n/=factor;
        return n;
    }
    bool isUgly(int n) {
        if(n<=0) return false;
        
        for(auto &factor : {2, 3, 5})
        {
            n=divide(n, factor);
        }
        
        return n==1;
    }
};