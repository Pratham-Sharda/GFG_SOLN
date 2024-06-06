//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void parenting(Node* root, map<Node*, Node*>& parent) {
        if (root == NULL) {
            return;
        }
        if (root->left) {
            parent[root->left] = root;
            parenting(root->left, parent);
        }
        if (root->right) {
            parent[root->right] = root;
            parenting(root->right, parent);
        }
    }
    Node* find_tar(Node* root,int target){
        if(root==NULL || root->data==target){
            return root;
        }
        
        Node* lefty=find_tar(root->left,target);
        Node* righty=find_tar(root->right,target);
        
        if(lefty){
            return lefty;
        }else{
            return righty;
        }
    }
    int minTime(Node* root, int target) 
    {   Node* targe=find_tar(root,target);
        // Your code goes here
        map<Node*, Node*> parent;
        parenting(root, parent);
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targe);
        int curr_level = -1;
        visited[targe] = true;

        while (!q.empty()) {
            int size = q.size();

            // if (k == curr_level) {
            //     break;
            // }
            curr_level++;
            for (int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();
                visited[temp] = true;
                if (temp->left && !visited[temp->left]) {
                    q.push(temp->left);
                }
                if (temp->right && !visited[temp->right]) {
                    q.push(temp->right);
                }
                if (parent[temp] && !visited[parent[temp]]) {
                    q.push(parent[temp]);
                }
            }
        }
        return curr_level;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends