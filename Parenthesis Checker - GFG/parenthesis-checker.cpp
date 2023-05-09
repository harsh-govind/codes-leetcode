//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> stk;
        
        for(int i=0; i<x.size(); i++)
        {
            char v=x[i];
            
            if((v==']' or v=='}' or v==')')and stk.size()==0)
            {
                return false;
            }
            
            if(v=='[' or v=='{' or v=='(')
            {
                stk.push(v);
            }
            else if((v==']' and stk.top()!='[') or (v=='}' and stk.top()!='{')  or (v==')' and stk.top()!='(')  )
            {
                return false;
            }
            else
            {
                stk.pop();
            }
        }
        
        if(stk.size()==0)
        {
            return true;
        }
        
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends