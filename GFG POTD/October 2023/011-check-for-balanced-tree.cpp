// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1


//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


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
/* A binary tree node structure

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

class Solution{
    
    int height(Node* root) {
        if (root == NULL) return 0;
        
        int left  = height(root -> left);
        int right = height(root -> right);
        
        return max(left, right) + 1;
    }
    
    
    // TC = O(N * N) 
    // SC = O(H)
    bool solve_brute(Node *root) {
        if (root == NULL) 
            return true;
            
        bool left  = solve_brute(root -> left);
        bool right = solve_brute(root -> right);
        bool diff  = abs( height(root -> left) - height(root -> right) ) <= 1;
        
        if (left && right && diff) return true;
        else return false;
    }
    
    // TC = O(N)
    // SC = O(H)
    pair<bool, int> solve_optimal(Node* root) {
        if (root == NULL) {
            pair<bool, int> p = make_pair(1, 0); // {isBalanced, height}
            return p;
        }
        
        pair<bool, int> left  = solve_optimal(root -> left);
        pair<bool, int> right = solve_optimal(root -> right);
        
        bool leftAns  = left.first;
        bool rightAns = right.first;
        bool diff     = abs(left.second - right.second) <= 1;
        
        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if (leftAns && rightAns && diff) {
            ans.first = true;
        }
        else {
            ans.first = false;
        }
        
        return ans;
    }
    
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        // return solve_brute(root);
        
        return solve_optimal(root).first;
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
        cout << ob.isBalanced(root) << endl;
    }
    return 0;
}

// } Driver Code Ends