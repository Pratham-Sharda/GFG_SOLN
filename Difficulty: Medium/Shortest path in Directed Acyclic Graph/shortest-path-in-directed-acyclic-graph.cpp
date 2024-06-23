//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void toposort(int node,stack<int> & st,vector<pair<int,int>> adj[],vector<int>& visited){
         visited[node]=1;
         
         for(auto i:adj[node]){
             int v=i.first;
             int wt=i.second;
             if(!visited[v]){
                
                 toposort(v,st,adj,visited);
             }
         }
         
         st.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        vector<int> dist(N);
        for(int i=0;i<N;i++){
            dist[i]=INT_MAX;
        }
        dist[0]=0;
        vector<int> visited(N,0);
        stack<int> st;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                toposort(i,st,adj,visited);
            }
        }
        
while (!st.empty()) {
    int node = st.top();
    st.pop();

    if (dist[node] != INT_MAX) { // Check if node is reachable
        for (auto i : adj[node]) {
            int v = i.first;
            int wt = i.second;
            if (dist[node] + wt < dist[v]) {
                dist[v] = dist[node] + wt;
            }
        }
    }
}
        
        
        for(int i=0;i<dist.size();i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends