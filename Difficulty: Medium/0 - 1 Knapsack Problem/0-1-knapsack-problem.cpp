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
       
       for(int i=wt[0];i<W+1;i++){
           dp[0][i]=val[0];
       }
       
       for(int idx=1;idx<n;idx++){
           for(int wei=0;wei<W+1;wei++){
               int no=dp[idx-1][wei];
               int yes=INT_MIN;
               if(wt[idx]<=wei){
                   yes=val[idx]+dp[idx-1][wei-wt[idx]];
               }
               
               dp[idx][wei]=max(yes,no);
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