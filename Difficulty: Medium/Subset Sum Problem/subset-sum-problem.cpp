//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        
        vector<vector<int>> dp(arr.size(),vector<int>(sum+1,0));
        
        for(int i=0;i<dp.size();i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<dp[0].size();i++){
            if(arr[0]==i){
                dp[0][i]=1;
            }
        }
        
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(j>=arr[i]){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[arr.size()-1][sum];
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends