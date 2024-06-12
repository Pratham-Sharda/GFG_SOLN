//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#include<algorithm>
class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        map<int,int> mpp;
        vector<int> dum=arr;
        sort(dum.begin(),dum.end());
        int temp=1;
        for(int i=0;i<dum.size();i++){
            if(mpp[dum[i]]==0){
                mpp[dum[i]]=temp;
                temp++;
            }
        }
        
        for(int i=0;i<dum.size();i++){
            int rank=mpp[arr[i]];
            arr[i]=rank;
        }
        return arr;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends