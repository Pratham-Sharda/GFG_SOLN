//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool detect(int node,vector<int>adj[],vector<int>& visited){
        visited[node]=1;
        queue<pair<int,int>> q;
        q.push({node,-1});
        
        while(!q.empty()){
            auto curr=q.front();
            int parent=curr.second;
            int curn=curr.first;
            q.pop();
            for(auto i:adj[curn]){
                if(!visited[i]){
                    visited[i]=1;
                    q.push({i,curn});
                }else if(visited[i]==1 && parent!=i){
                    return true;
                }
            }
        }
        
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detect(i,adj,visited)){
                    return true;   
                }
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends