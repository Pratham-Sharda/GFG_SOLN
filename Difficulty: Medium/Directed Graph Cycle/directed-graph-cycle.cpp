//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs_cycle(int node,vector<int>& visited,vector<int>& pathvisited,vector<int> adj[]){
        visited[node]=1;
        pathvisited[node]=1;
        
        for(auto i:adj[node]){
            if(!visited[i]){
                if(dfs_cycle(i,visited,pathvisited,adj)){
                    return true;
                }
            }else if(pathvisited[i]){
                return true;
            }
        }
        
        pathvisited[node]=0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,0);
        vector<int> pathvisited(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs_cycle(i,visited,pathvisited,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends