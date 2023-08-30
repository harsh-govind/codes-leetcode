//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve(int i, string s, set<string> &tempAns)
	    {
	        if(i==s.size())
	        {
	            tempAns.insert(s);
	            return;
	        }
	        
	        for(int k=i; k<s.size(); k++)
	        {
	            swap(s[i], s[k]);
	            solve(i+1, s, tempAns);
	            swap(s[i], s[k]);
	        }
	    }
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    set<string> tempAns;
		    solve(0, s, tempAns);
		    
		    vector<string> ans(tempAns.begin(), tempAns.end());
		    
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends