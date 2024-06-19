//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<pair<int,int>> bfs(int row,int col,vector<vector<int>>& grid,
    vector<vector<int>>& visited,int i0,int j0){
        queue<pair<int,int>> q;
        visited[row][col]=1;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int,int>> ans;
        ans.push_back({row-i0,col-j0});
        while(!q.empty()){
            auto node=q.front();q.pop();
            int cr=node.first;
            int cl=node.second;
            
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int nr=cr+delrow[i];
                int nl=cl+delcol[i];
                
                if(nr>=0 &&nr<n && nl>=0 && nl<m && grid[nr][nl]==1 && !visited[nr][nl]){
                    visited[nr][nl]=1;
                    q.push({nr,nl});
                    ans.push_back({nr-i0,nl-j0});
                }
            }
        }
        
        return ans;
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>> s;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    vector<pair<int,int>> island=bfs(i,j,grid,visited,i,j);
                    
                    
                    s.insert(island);
                }
            }
        }
        
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends