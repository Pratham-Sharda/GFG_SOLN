//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    long long maximumAmount(int n, int arr[]) {
        // Create a 2D dp array initialized to 0
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        // Initialize the dp array where i == j
        for (int i = 0; i < n; i++) {
            dp[i][i] = (long long)arr[i];
        }

        // Fill the dp array for all subarray lengths
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;

                // Make sure to handle boundaries correctly
                long long opt1 = arr[i] + min((i + 2 <= j ? dp[i + 2][j] : 0), (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0));
                long long opt2 = arr[j] + min((i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0), (i <= j - 2 ? dp[i][j - 2] : 0));

                dp[i][j] = max(opt1, opt2);
            }
        }

        return dp[0][n - 1];
    }
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends