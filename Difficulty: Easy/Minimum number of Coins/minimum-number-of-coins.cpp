//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        int arr[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        vector<vector<int>> dp(10,vector<int>(N+1,0));
        for(int i=0;i<10;i++){
            dp[i][0]=0;
            
        }
        
        for(int i=0;i<=N;i++){
            dp[0][i]=i;
        }
        
        for(int i=1;i<10;i++){
            for(int j=1;j<=N;j++){
                if(j>=arr[i]){
                    int one=1+dp[i][j-arr[i]];
                    int two=dp[i-1][j];
                    dp[i][j]=min(one,two);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        vector<int> ans;
        int val=N;
        int idx=9;
        while(val!=0 && idx>0){
            if(val>=arr[idx]){
                int opt1=1+dp[idx][val-arr[idx]];
                int opt2=dp[idx-1][val];
                if(opt1<opt2){
                    ans.push_back(arr[idx]);
                    val=val-arr[idx];
                }else{
                    idx--;
                }
            }else{
                idx--;
            }
        }
        if(val){
            for(int i=0;i<val;i++){
                ans.push_back(1);
            }
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends