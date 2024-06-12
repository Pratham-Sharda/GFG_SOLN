//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++
class note{
    public:
    int data;
    int rownum;
    int colnum;
     note(int data,int row,int col){
         this->data=data;
         this->rownum=row;
         this->colnum=col;
     }
};

class compare{
  public:
  bool operator()(note* a,note* b){
      return (a->data>b->data);
  }  
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> ans;
        priority_queue<note*,vector<note*>,compare> p;
        
        for(int i=0;i<K;i++){
            
            if (!arr[i].empty()) {  // Ensure the array is not empty
                note* te = new note(arr[i][0], i, 0);
                p.push(te);
            }
        }
        
        while(!p.empty()){
            note* temp=p.top();
            p.pop();
            
            int val=temp->data;
            int col=temp->colnum;
            int row=temp->rownum;
            ans.push_back(val);
            if(col+1<arr[row].size()){
                note* next=new note(arr[row][col+1],row,col+1);
                p.push(next);
            }
            delete(temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends