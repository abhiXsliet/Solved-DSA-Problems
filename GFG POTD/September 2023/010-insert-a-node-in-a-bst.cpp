// https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// } Driver Code Ends
// Function to insert a node in a BST.

/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// TC = O(H)
// SC = O(H)
class Solution
{
    private:
        Node* solve(Node* node, int k) {
            if (!node) return new Node(k);
            
            while(1) {
                if (k > node -> data) {
                    if (node -> right == NULL) {
                        node -> right = new Node(k);
                        break;
                    }
                    else 
                        node = node -> right;
                }
                else if (k < node -> data){
                    if (node -> left == NULL) {
                        node -> left = new Node(k);
                        break;
                    }
                    else
                        node = node -> left;
                }
                else {
                    return node; 
                }
            }
            return node;
        }
        
        Node* solve2(Node* node, int k) {
            if(!node) return new Node(k);
            
            if (k < node -> data)
                node -> left = solve2(node -> left, k);
            else if (k > node -> data)
                node -> right = solve2(node -> right, k);
                
            return node;
        }
    public:
        Node* insert(Node* node, int data) {
        
            // return solve(node, data);
            
            return solve2(node, data);
            
    }

};


//{ Driver Code Starts.

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
    Node* root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (root == NULL) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        getline(cin, s);
        int k = stoi(s);
        // getline(cin, s);
        Solution ob;
        ob.insert(root, k);
        vector<int> v;
        inorder(root, v);
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;

        // cout<<"~"<<endl;
    }
    return 0;
}

// } Driver Code Ends