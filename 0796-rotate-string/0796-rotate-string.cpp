class Solution {
public:
    string rotate(string &b)
    {
        char temp=b[0];
        int n=b.size();
        for(int i=0; i<n-1; i++)
        {
            b[i]=b[i+1];
        }
        b[n-1]=temp;
        return b;
    }
    bool rotateString(string a, string b) {
        if(a==b or a.size()==0 or b.size()==0) return true;
        if(a.size()!=b.size()) return false;
        
        int n=a.size();
        
        for(int i=0; i<n; i++)
        {
            if(a==rotate(b)) return true;       
        }
        return false;
    }
};