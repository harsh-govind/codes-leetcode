//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans="";
		    queue<char> q;
		    unordered_map<char, int> m;
		    
		    for(auto &c:A)
		    {
		        m[c]++;
		        q.push(c);
		        
		        while(!q.empty() and m[q.front()]>1)
		        {
		            q.pop();
		        }
		        
		        if(q.empty())
		        {
		            ans.push_back('#');
		        }
		        else
		        {
		            ans.push_back(q.front());
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends