//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum) {
        const int MOD = 1e9 + 7;
        
        // Initialize a DP array
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        
        // There is one way to achieve sum 0: using the empty subset
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        
        // Fill the dp array
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= sum; ++j) {
                if (arr[i - 1] <= j) {
                    // Include the current element or exclude it
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % MOD;
                } else {
                    // Exclude the current element
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends