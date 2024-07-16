//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long maxProduct(int n) {
        // code here
        vector<long long> dp(n+1,0);
        dp[1]=0;
        for(long long i=2;i<=n;i++){
            long long mini=0;
            for(long long j=1;j<i;j++){
                mini=max(mini , (long long )j*(i-j));
                mini=max(mini , j*dp[i-j]);
            }
            dp[i]=mini;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.maxProduct(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends