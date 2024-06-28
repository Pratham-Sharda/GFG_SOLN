//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                if(j!=k)
                    dp[n-1][j][k]=grid[n-1][j]+grid[n-1][k];
                else
                    dp[n-1][j][k]=grid[n-1][j];
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++){
                    int maxi=-1e9;
                    
                    for(int dj=-1;dj<=1;dj++){
                        for(int dk=-1;dk<=1;dk++){
                            int val=0;
                            if(j!=k){
                                val=grid[i][j]+grid[i][k];
                            }else{
                                val=grid[i][j];
                            }
                            
                            if(j+dj>=0 && j+dj<m && k+dk>=0 && k+dk<m){
                                val+=dp[i+1][j+dj][k+dk];
                            }else{
                                val+=-1e9;
                            }
                            
                            maxi=max(maxi,val);
                        }
                    }
                    dp[i][j][k]=maxi;
                }
            }
        }
        
        return dp[0][0][m-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends