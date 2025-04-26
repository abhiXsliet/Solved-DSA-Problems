// https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
  public:
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
// User Function template for C++

// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  private:
    bool isMaxHeap(Node* root) {
        if (!root) return true;
        
        if (root -> left  && root -> data < root -> left -> data) 
            return false;
        
        if (root -> right && root -> data < root -> right -> data)
            return false;
        
        return isMaxHeap(root -> left) && isMaxHeap(root -> right);
    }
    
    bool isValidIdx(Node* root, int totalNodes, int index) {
        if (!root) return true;
        if (index >= totalNodes) return false;
        
        if (!isValidIdx(root -> left, totalNodes, 2*index + 1))
            return false;
        
        return isValidIdx(root -> right, totalNodes, 2*index + 2);
    }
    
    int getNodesCnt(Node* root) {
        if (!root) return 0;
        return 1 + getNodesCnt(root -> left) + getNodesCnt(root -> right);
    }
    
    // TC : O(N)
    // SC : O(N)
    bool isCBT1(Node* root) {
        queue<Node*> q;
        q.push(root);
        bool isNull = false;
        while (!q.empty()) {
            Node* fNode = q.front();
            q.pop();
            
            if (!fNode) {
                isNull = true;
            } else {
                if (isNull) return false;
                q.push(fNode ->  left);
                q.push(fNode -> right);
            }
        }
        return true;
    }
    
    // TC : O(N)
    // SC : O(1)
    bool isCBT2(Node* tree) {
        // count total no. of nodes
        int totalNodes = getNodesCnt(tree);
        // check if the index <= totalNodes
        return isValidIdx(tree, totalNodes, 0);
    }
    
    bool isComplete(Node* tree) {
        // return isCBT1(tree);    // bfs
        return isCBT2(tree); // dfs : counting of nodes and verifying index <= totalNodes
    }
  public:
    bool isHeap(Node* tree) {
        return isComplete(tree) && isMaxHeap(tree);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends