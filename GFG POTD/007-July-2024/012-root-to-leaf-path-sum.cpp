// https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1



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
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution {
  private:
    // TC : O(N)
    // SC : O(H)
    bool approach_1(Node* root, int target) {
        if (!root -> left && !root -> right && target == root -> data) 
            return true;
        
        bool left = 0, right = 0;
        if (root -> left) 
            left  = hasPathSum(root -> left , target - root -> data);
        if (root -> right) 
            right = hasPathSum(root -> right, target - root -> data);
            
        return left || right;
    }
    
    // TC : O(N)
    // SC : O(H)
    bool approach_2(Node* root, int target) {
        if (!root) return false;
        if (!root -> left && !root -> right) 
            return target == root -> data;
            
        return hasPathSum(root -> left , target - root -> data) || 
               hasPathSum(root -> right, target - root -> data);
    }
  public:
    bool hasPathSum(Node* root, int target) {
        // return approach_1(root, target);
        return approach_2(root, target);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int sum;
        scanf("%d ", &sum);
        // if (sum == 2) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool r = ob.hasPathSum(root, sum);
        if (r)
            cout << "true"
                 << "\n";
        else
            cout << "false"
                 << "\n";
    }
    return 0;
}
// } Driver Code Ends