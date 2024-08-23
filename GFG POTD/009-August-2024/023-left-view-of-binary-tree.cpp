// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> leftView(struct Node *root);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> vec = leftView(root);
        for(int x : vec)
        cout << x <<" ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/* A binary tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// TC : O(N)
// SC : O(N) Where N = No. of Nodes
vector<int> approach_1(Node* root) {
    queue<Node*> q;
    vector<int> result;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        result.push_back(q.front() -> data);
        while (size --) {
            Node* fNode = q.front();
            q.pop();
            
            if (fNode -> left)  q.push(fNode -> left);
            if (fNode -> right) q.push(fNode -> right);
        }
    }
    return result;
}

// TC : O(N)
// SC : O(N)
void approach_2(Node* root, int level, vector<int>& result) {
    if (!root) return;
    
    if (result.size() == level)
        result.push_back(root -> data);
        
    approach_2(root -> left , level + 1, result);
    approach_2(root -> right, level + 1, result);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root) {
    // return approach_1(root);    // Level Order Traversal
    
    vector<int> result;
    approach_2(root, 0, result);
    return result;
}