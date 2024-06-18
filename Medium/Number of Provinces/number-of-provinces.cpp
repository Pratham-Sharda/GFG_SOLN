//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void bfs(int node,vector<int>& visited,vector<vector<int>>& lis){
        visited[node]=1;
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int vurr=q.front();
            q.pop();
            for(auto i:lis[vurr]){
                if(!visited[i]){
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> lis(n);

        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]){
                    lis[i].push_back(j);
                }
                
            }
        }
        
        int ctr=0;
        vector<int> visited(n,0);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(i,visited,lis);
                ctr++;
            }
        }

        return ctr;
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        return findCircleNum(adj);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends