// https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
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

/* 
A binary tree node has data, pointer to left child and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; 
*/

// ----------------------------------- APPROACH - 1 : (PREORDER TRAVERSAL with Storage of -1 in preorder array if Null is encountered) --------------------------------------------------------
// TC : O(N)
// SC : O(N) for both serialize and deserialize
class Solution {
  public:
    void getPreOrder(Node *root, vector<int>& preOrder) {
        if (!root) {
            preOrder.push_back(-1);
            return;
        }
        preOrder.push_back(root -> data);
        getPreOrder(root ->  left, preOrder);
        getPreOrder(root -> right, preOrder);
    }
    
    Node* generateTree(vector<int>& preOrder, int n, int &i) {
        if (i >= n || preOrder[i] == -1) {
            i ++;   // catch
            return NULL;
        }
        
        Node* root = new Node(preOrder[i ++]);
        
        root ->  left = generateTree(preOrder, n, i);
        root -> right = generateTree(preOrder, n, i);
        
        return root;
    }
    
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        vector<int> preOrder;
        getPreOrder(root, preOrder);
        return preOrder;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        int index = 0;
        return generateTree(arr, arr.size(), index);
    }
};

// ----------------------------------- APPROACH - 2 : (LEVEL-ORDER TRAVERSAL with storage of -1 in preorder array if Null is encountered) --------------------------------------------------------
// TC : O(N)
// SC : O(N) for both serialize and deserialize
class Solution {
    public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        vector<int> result;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node *fNode = q.front();
            q.pop();

            if (!fNode) {
                result.push_back(-1);
                continue;
            }

            result.push_back(fNode->data);
            q.push(fNode->left);
            q.push(fNode->right);
        }
        return result;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        if (arr[0] == -1)
            return NULL; // if there's no root then -1 get inserted while serialization in result

        Node *root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
        int i = 1;

        while (!q.empty()) {
            Node *fNode = q.front();
            q.pop();

            // if left child is not null
            if (arr[i] != -1) {
                fNode->left = new Node(arr[i]);
                q.push(fNode->left);
            }
            i++;

            // if right child is not null
            if (arr[i] != -1) {
                fNode->right = new Node(arr[i]);
                q.push(fNode->right);
            }
            i++;
        }

        return root;
    }
};


//{ Driver Code Starts.
void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node *node) {
    if (node == NULL)
        return;

    /* first delete both subtrees */
    _deleteTree(node->left);
    _deleteTree(node->right);

    /* then delete the node */
    // cout << "Deleting node: " << node->data << endl;
    delete node;
}

/* Deletes a tree and sets the root as NULL */
void deleteTree(Node **node_ref) {
    _deleteTree(*node_ref);
    *node_ref = NULL;
}

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);

        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        Node *temp = root;
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        inorder(getRoot);

        cout << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends