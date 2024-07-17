//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete below method */

class Solution{
    public:
    int minSum(int arr[], int n){
        //Write your code here
        vector<int> dp(n,0);
        
        for(int i=0;i<4;i++){
            dp[i]=arr[i];
        }
        // int mini=1e9;
        for(int i=4;i<n;i++){
            int minval=1e9;
            for(int j=i-1;j>=i-4;j--){
                minval=min(minval,dp[j]);
            }
            dp[i]=minval+arr[i];
            // mini=min(mini,dp[i]);
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<dp[i]<<" ";
        // }
        int mini=1e9;
        for(int i=n-1;i>=0 && i>=n-4;i-- ){
            mini=min(mini,dp[i]);
        }
        // cout<<endl;
        return mini;
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
		cout<< ob.minSum(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends