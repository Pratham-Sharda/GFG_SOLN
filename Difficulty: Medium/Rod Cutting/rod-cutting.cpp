//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        
        
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        
        for(int i=0;i<=n;i++){
            dp[0][i]=i*price[0];
            // cout<<dp[0][i]<<".";
        }
        // cout<<endl;
        
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        
        for(int i=1;i<n;i++){
            int cursize=i+1;
            for(int j=1;j<n+1;j++){
                int no=dp[i-1][j];
                int take=-1e9;
                if(j>=cursize){
                    take=price[i]+dp[i][j-cursize];
                }
                
                dp[i][j]=max(no,take);
                // cout<<dp[i][j]<<".";
            }
            // cout<<endl;
        }
        
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends