//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    //{isbst,min,max,size};
    // vector<int> solver(Node* root,int & maxi){
    //     if(!root->left && !root->right){
    //         maxi=max(maxi,1);
    //         return {1,root->data,root->data,1};
    //     }
    //     vector<int> lefty={1,INT_MAX,INT_MIN,0};
    //     if(root->left){
    //         lefty=solver(root->left,maxi);
    //     }
    //     vector<int> righty={1,INT_MAX,INT_MIN,0};
    //     if(root->right){
    //         righty=solver(root->right,maxi);
    //     }
        
        
    //     if(righty[0] && lefty[0] && root->data>lefty[2] && root->data<righty[1]){
    //         maxi=max(maxi,lefty[3]+righty[3]+1);
    //         return {1,lefty[1],righty[2],lefty[3]+righty[3]+1};
    //     }else{
    //         return{0,min(lefty[1],root->data),max(root->data,righty[2]),0};
    //     }
    // }
    // int largestBst(Node *root)
    // {
    // 	//Your code here
    // 	int maxi=0;
    	
    // 	solver(root,maxi);
    	
    // 	return maxi;
    // }
    
    vector<int> solver(Node* root, int &maxi) {
    if (!root->left && !root->right) {
        maxi = max(maxi, 1);
        return {1, root->data, root->data, 1};
    }

    vector<int> lefty = {1, INT_MAX, INT_MIN, 0};
    if (root->left) {
        lefty = solver(root->left, maxi);
    }

    vector<int> righty = {1, INT_MAX, INT_MIN, 0};
    if (root->right) {
        righty = solver(root->right, maxi);
    }

    if (lefty[0] && righty[0] && root->data > lefty[2] && root->data < righty[1]) {
        int current_size = lefty[3] + righty[3] + 1;
        maxi = max(maxi, current_size);
        return {1, min(lefty[1], root->data), max(root->data, righty[2]), current_size};
    } else {
        return {0, min(lefty[1], root->data), max(root->data, righty[2]), -1};
    }
}

int largestBst(Node* root) {
    int maxi = 0; // Initialize maxi to 0
    solver(root, maxi);
    return maxi;
}
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends