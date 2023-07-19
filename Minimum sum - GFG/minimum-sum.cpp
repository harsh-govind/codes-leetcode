//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    string stringSum(const std::string& str1, const std::string& str2) {
        int i = str1.length() - 1;
        int j = str2.length() - 1;
        int carry = 0;
        std::string result;
    
        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;
            if (i >= 0) {
                sum += str1[i] - '0';
                i--;
            }
    
            if (j >= 0) {
                sum += str2[j] - '0';
                j--;
            }
    
            carry = sum / 10;
            sum %= 10;
    
            result = char(sum + '0') + result;
        }
    
        size_t pos = result.find_first_not_of('0');
        if (pos != std::string::npos) {
            result = result.substr(pos);
        } else {
            result = "0"; // If the result is "0", return it as is.
        }
    
        return result;
    }
    string solve(int arr[], int n) {
        // code here
        sort(arr, arr+n);
        int i=0;
        
        string a="", b="";
        while(i<n)
        {
            if(i<n)
            {
                a+=to_string(arr[i++]);
            }
            
            if(i<n)
            {
                b+=to_string(arr[i++]);
            }
        }
        return stringSum(a,b);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends