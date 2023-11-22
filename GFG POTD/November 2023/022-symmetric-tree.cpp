// https://www.geeksforgeeks.org/problems/symmetric-tree/1



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
/*
Structure of the node of the tree is as
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
class Solution{
    private:
    // TC = O(N)
    // SC = O(H)
    bool isMirror_1(struct Node* root1, struct Node* root2) {
        if (root1 == NULL && root2 == NULL) 
            return true;
        
        if (root1 != NULL && root2 != NULL && root1 -> data == root2 -> data) {
            return ( isMirror_1(root1 -> left, root2 -> right) &&
                     isMirror_1(root1 -> right, root2 -> left) );
        }
        
        return false;
    }
    
    // TC = O(N)
    // SC = O(N)
    bool isMirror_2(struct Node* root) {
        if (root == NULL) return true;
        
        stack<Node*> st;
        st.push(root -> left);
        st.push(root -> right);
        
        while(!st.empty()) {
            Node* n1 = st.top(); st.pop();
            Node* n2 = st.top(); st.pop();
            
            if (n1 == NULL && n2 == NULL) continue;
            if (n1 == NULL || n2 == NULL) return false;
            if (n1 -> data != n2 -> data) return false;
            
            st.push(n1 -> right); st.push(n2 -> left);
            st.push(n1 -> left); st.push(n2 -> right);
        }
        
        return true;
    }
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
        // return isMirror_1(root, root);
        
        return isMirror_2(root);
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

        vector<int> ans;
        Solution ob;
        if(ob.isSymmetric(root)){
            cout<<"True"<<endl;
        }
        else{ 
            cout<<"False"<<endl;
        }
    }
    return 0;
}

// } Driver Code Ends