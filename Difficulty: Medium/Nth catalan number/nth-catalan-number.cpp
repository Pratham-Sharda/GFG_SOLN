//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    
    int findCatalan(int n) 
    {
        //code here
        // return f(n,n);
        int mod=1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=0;i<n+1;i++){
            dp[0][i]=1;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(i>j){
                    continue;
                }
                else if(i==j){
                    dp[i][j]=dp[i-1][j]%mod;
                }
                else{
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
                }
            }
        }
        
        return dp[n][n]%mod;
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends