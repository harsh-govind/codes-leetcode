//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string s){
		    int m, n;
		    m=n=s.size();
		    int t[m+1][n+1];
		    
		    for(int i=0;i<n+1;i++)
		    {
		        t[i][0]=t[0][i]=0;

		    }
		    
		    for(int i=1;i<m+1;i++)
		    {
		        for(int j=1;j<n+1; j++)
		        {
		            if(s[i-1]==s[j-1] and i!=j)
		            {
		                t[i][j]=1+t[i-1][j-1];
		            }
		            else
		            {
		                t[i][j]=max(t[i-1][j], t[i][j-1]);
		            }
		        }
		    }
		    
		    return t[m][n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends