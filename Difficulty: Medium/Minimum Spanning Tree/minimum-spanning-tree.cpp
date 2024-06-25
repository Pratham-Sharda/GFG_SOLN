//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int find(vector<int>& parent,int node){
	    if(parent[node]==node){
	        return node;
	    }
	    return parent[node]=find(parent,parent[node]);
	}
	
	void uni(vector<int> & parent, vector<int> &rank,int u, int v){
	    int pu=find(parent,u);
	    int pv=find(parent,v);
	    int ru=rank[pu];
	    int rv=rank[pv];
	    
	    if(ru<rv){
	        parent[pu]=pv;
	    }else if(rv<ru){
	        parent[pv]=pu;
	    }else{
	        parent[pv]=pu;
	        rank[pu]++;
	    }
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<pair<int,pair<int,int>>> edges; //wt,u,v
        for(int i=0;i<V;i++){
            int node=i;
            for(auto it:adj[node]){
                int nbr=it[0];
                int wt=it[1];
                edges.push_back({wt,{node,nbr}});
            }
        }
        vector<int> parent(V,0);
        vector<int> rank(V,0);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        int mst=0;
        sort(edges.begin(),edges.end());
        for(auto i:edges){
            int wt=i.first;
            int u=i.second.first;
            int v=i.second.second;
            
            if(find(parent,u)!=find(parent,v)){
                mst+=wt;
                uni(parent,rank,u,v);
            }
            
        }
        
        return mst;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends