//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int, int>> v;
	    int ans=0;
	    for(int i=0; i<nums.size(); i++)
	    {
	        v.push_back({nums[i], i});
	    }
	    sort(v.begin(), v.end());
	    for(int i=0; i<v.size(); i++)
	    {
	        int val=v[i].first, index=v[i].second;
	        if(index!=i)
	        {
	            swap(v[i], v[index]);
	            ans++;
	            i--;
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
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends