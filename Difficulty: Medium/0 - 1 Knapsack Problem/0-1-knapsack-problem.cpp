//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,0));
       
       for(int i=0;i<W+1;i++){
           if(wt[0]<=i){
               dp[0][i]=val[0];
           }
       }
       
       for(int i=1;i<n;i++){
           for(int j=1;j<W+1;j++){
               int nottake=dp[i-1][j];
               int take=0;
               if(j>=wt[i]){
                   take=dp[i-1][j-wt[i]] +val[i];
               }
               dp[i][j]=max(take,nottake);
           }
       }
       
       return dp[n-1][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends