//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    const long long int MOD = 1e9 + 7;

    // Helper function for top-down approach
    long long int helper(int n, vector<int>& dp){
        // Base case: if n is less than or equals to 1, return n
        if (n <= 1) return dp[n] = n;

        // If result already exists in dp array, return it
        if (dp[n] != -1) return dp[n];
        
        // Recursively calculate the Fibonacci number and store it in dp array
        return dp[n] = (helper(n - 1, dp) + helper(n - 2, dp)) % MOD;
    }

    // Top-down approach to calculate Fibonacci number
    long long int topDown(int n) {
        // Create a dp array and initialize it with -1 indicating no result yet
        vector<int> dp(n + 1, -1);
        // Call helper function to calculate Fibonacci number using top-down approach
        return helper(n, dp); 
    }
    
    // Bottom-up approach to calculate Fibonacci number
    long long int bottomUp(int n) {
        // Create a dp array and initialize it with -1 indicating no result yet
        vector<long long int> dp1(n + 1, -1);

        // Base cases
        dp1[0] = 0;
        dp1[1] = 1;

        // Start from 2 and calculate Fibonacci numbers iteratively
        for (int i = 2; i <= n; i++) {
            dp1[i] = (dp1[i - 1] + dp1[i - 2]) % MOD;
        }
        // Return the Fibonacci number for n
        return dp1[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends