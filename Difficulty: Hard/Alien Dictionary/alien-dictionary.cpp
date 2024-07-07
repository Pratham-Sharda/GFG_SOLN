//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int diffe(string s1,string s2){
        int i=min(s1.length(),s2.length());
        int ctr=0;
        while(ctr<i){
            if(s1[ctr]!=s2[ctr]){
                return ctr;
            }ctr++;
        }
        return ctr;
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        map<char,vector<char>> mpp;
        
        for(int i=0;i<N-1;i++){
            int difidx=diffe(dict[i],dict[i+1]);
            mpp[dict[i][difidx]].push_back(dict[i+1][difidx]);
        }
        
        
        map<char,int> indegree;
        for(auto i:mpp){
            for(auto it:i.second){
                indegree[it]++;
            }
        }
        
        string ans="";
        queue<char> q;
        for(auto i:mpp){
            char from =i.first;
            if(indegree.find(from)==indegree.end()){
                q.push(from);
            }
        }
        
        while(!q.empty()){
            char curr=q.front();q.pop();
            ans.push_back(curr);
            
            for(auto it:mpp[curr]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends