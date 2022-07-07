class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(auto &val:s)
        {
            if(val>='a' and val<='z' || val>='A' and val<='Z' || val>='0' and val <='9')
            {
                if(val>='A' and val<='Z')
                {
                   val= tolower(val);
                }
                temp+=val;
            }
        }
        int n = temp.size();
        cout<<temp;
        for(int i=0;i<(n/2);i++)
        {
            if(temp[i]!=temp[n-i-1])
            {
                return false;
            }
        }
        return true;
    }
};