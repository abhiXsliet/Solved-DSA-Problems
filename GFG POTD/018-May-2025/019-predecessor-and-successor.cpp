// https://www.geeksforgeeks.org/problems/predecessor-and-successor/1




//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
// } Driver Code Ends

/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  private:
    void inorder(Node* root, vector<int> &store) {
        if (!root) return;
        
        inorder(root ->  left, store);
        store.push_back(root -> data);
        inorder(root -> right, store);
    }
    
    // TC : O(N + N*log(N))
    // SC : O(N)
    vector<Node*> brute(Node *root, int key) {
        vector<int> store;
        inorder(root, store);
        
        sort(begin(store), end(store));
        
        int idx = lower_bound(begin(store), end(store), key) - begin(store);

        int successor = -1, predecessor = -1;
        if (store[idx] > key) successor = store[idx];
        else successor = (idx + 1 < store.size()) ? store[idx + 1] : -1;
        predecessor = (idx - 1) >= 0 ? store[idx - 1] : -1;
        
        if (successor == -1 && predecessor == -1) 
            return {NULL, NULL};
        else if (successor == -1) 
            return {new Node(predecessor), NULL};
        else if (predecessor == -1) 
            return {NULL, new Node(successor)};
        return {new Node(predecessor), new Node(successor)};
    }
    
    void solve(Node *root, int key, int &pred, int &succ) {
        if (!root) return;
        
        if (root -> data < key && root -> data > pred)
            pred = root -> data;
        if (root -> data > key && root -> data < succ) 
            succ = root -> data;
            
        solve(root ->  left, key, pred, succ);
        solve(root -> right, key, pred, succ);
    }
        
    // TC : O(H)
    // SC : O(1)
    vector<Node*> optimal(Node *root, int key) {
        int predecessor = INT_MIN, successor = INT_MAX;
        solve(root, key, predecessor, successor);
        if (predecessor == INT_MIN && successor == INT_MAX) {
            return {NULL, NULL};
        } else if (predecessor == INT_MIN) {
            return {NULL, new Node(successor)};
        } else if (successor == INT_MAX) {
            return {new Node(predecessor), NULL};
        }
        return {new Node(predecessor), new Node(successor)};
    }
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // return brute(root, key);
        
        return optimal(root, key);
    }
};
//{ Driver Code Starts.

Node* buildTree(string str) {
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
        if (i >= ip.size())
            break;
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

// Driver program to test above functions
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
        int key = stoi(s);

        Solution ob;
        vector<Node*> result = ob.findPreSuc(root, key);
        Node* pre = result[0];
        Node* suc = result[1];

        if (pre != nullptr)
            cout << pre->data << " ";
        else
            cout << -1 << " ";

        if (suc != nullptr)
            cout << suc->data << endl;
        else
            cout << -1 << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends