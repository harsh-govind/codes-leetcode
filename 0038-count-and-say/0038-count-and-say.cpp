class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        
        
        for(int k=2; k<=n; k++)
        {
           string temp="";
            
            int i=0, j=0, n=ans.size();
            
            while(i<n and j<n)
            {
                while(i<n and j<n and ans[i]==ans[j])
                {
                    j++;
                }
                
                temp+=to_string(j-i)+ans[i];
                i=j;
            }
            
            ans=temp;
        }
        
        return ans;
    }
};