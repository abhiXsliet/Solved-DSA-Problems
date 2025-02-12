// https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1




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

// Function to Build Tree
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


// } Driver Code Ends
/*Complete the function below

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
  private:
    // TC : O(N)
    // SC : O(H)
    void inorder(Node *root, vector<int>& store) {
        if (!root) return;
        inorder(root ->  left, store);
        store.push_back(root -> data);
        inorder(root -> right, store);
    }
    
    // TC : O(N)
    // SC : O(N)
    int approach_1(Node *root, int k) {
        vector<int> storeInorder;
        inorder(root, storeInorder);
        return k > storeInorder.size() ? -1 : storeInorder[k - 1];
    }
    
    // TC : O(N)
    // SC : O(H)
    int approach_2(Node *root, int &k) {
        if (!root) return -1;

        // Traverse the left subtree
        int left = approach_2(root->left, k);
        if (left != -1) return left;
    
        // If the current node is the k-th smallest element
        k--;
        if (k == 0) return root->data;
    
        // Traverse the right subtree
        return approach_2(root->right, k);
    }
  public:
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        // return approach_1(root, k);
        return approach_2(root, k);
    }
};

//{ Driver Code Starts.
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
        //  getline(cin, s);
        Solution obj;
        cout << obj.kthSmallest(root, k) << endl;
        // cout<<"~"<<endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends