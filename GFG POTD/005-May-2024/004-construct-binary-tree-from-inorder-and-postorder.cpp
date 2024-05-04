// https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1



//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}
// } Driver Code Ends
/* Tree node structure
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
    private:
    // TC : O(N^2)
    // SC : O(N) -> Recursive Depth
    Node* solve(int in[], int post[], int inStart, int inEnd, int poStart, int poEnd) {
        if (inStart > inEnd) return NULL;
        
        Node* root = new Node(post[poEnd]);
        
        // find the index of root node into inorder array
        int idx = inStart;
        for (; idx < inEnd; idx ++) {
            if (in[idx] == post[poEnd]) break;
        }
        
        int leftSize  = idx - inStart; // Left size of the inorder
        int rightSize = inEnd - idx;   // Right size of the inorder

        root -> left  = solve(in, post, inStart, idx - 1, poStart, poStart + leftSize - 1);
        root -> right = solve(in, post, idx + 1, inEnd  , poEnd - rightSize, poEnd - 1);
        
        return root;
    }
    
    // TC : O(N)
    // SC : O(N) 
    Node* optimal(int in[], int post[], int inStart, int inEnd, 
                  int poStart, int poEnd, unordered_map<int, int>& mpp) {
                      
        if (inStart > inEnd) return NULL;
        
        Node* root = new Node(post[poEnd]);
        
        // find the index of root node into inorder array
        int idx = mpp[root -> data];
        
        int leftSize  = idx - inStart; // Left size of the inorder
        int rightSize = inEnd - idx;   // Right size of the inorder

        root -> left  = optimal(in, post, inStart, idx - 1, poStart, poStart + leftSize - 1, mpp);
        root -> right = optimal(in, post, idx + 1, inEnd  , poStart + leftSize, poEnd - 1, mpp);
        
        return root;
    }
    public:
    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // return solve(in, post, 0, n - 1, 0, n - 1);
        
        unordered_map<int, int> mpp; // store indices of inorder elements
        for (int i = 0; i < n; i++) {
            mpp[in[i]] = i;
        }
        return optimal(in, post, 0, n - 1, 0, n - 1, mpp);
    }
};


//{ Driver Code Starts.
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends