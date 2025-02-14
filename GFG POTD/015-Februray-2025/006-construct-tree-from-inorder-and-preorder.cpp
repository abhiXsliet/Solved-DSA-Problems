// https://www.geeksforgeeks.org/problems/construct-tree-1/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}
// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

class Solution{
    public:
    Node* func(vector<int> &in, vector<int> &pre, unordered_map<int, int> &mpp, int &preIdx, int n, int inStart, int inEnd) {
        if (inStart > inEnd)
            return NULL;
        
        int element  = pre[preIdx ++];
        Node* root   = new Node(element);
        int position = mpp[element];
        
        root ->  left = func(in, pre, mpp, preIdx, n, inStart, position - 1);
        root -> right = func(in, pre, mpp, preIdx, n, position + 1, inEnd);
    
        return root;
    }
    
    Node* solve(vector<int>& in, vector<int>& pre, int &preIdx, int n, int inStart, int inEnd){
        //base case
        if(preIdx >= n || inStart > inEnd){
            return NULL;
        }
        
        int element  = pre[preIdx++];
        Node* root   = new Node(element);
        int position = inStart;
        
        for(; position < inEnd; position++){
            if(in[position] == element) break;
        }
        
        root -> left = solve(in, pre, preIdx, n, inStart, position - 1);
        root -> right= solve(in, pre, preIdx, n,  position + 1, inEnd);
        
        return root;
    }
    
    // TC : O(N^2)
    // SC : O(1)
    Node* approach_1(vector<int>& in, vector<int>& pre) {
        int n = in.size();
        int preIdx = 0;
        Node* ans = solve(in, pre, preIdx, n, 0, n - 1);
        return ans;
    }
    
    // TC : O(N)
    // SC : O(N)
    Node* approach_2(vector<int>& in, vector<int>& pre) {
        int n = in.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i ++) {
            mpp[in[i]] = i;
        }
        
        int preIdx = 0;
        Node* ans = func(in, pre, mpp, preIdx, n, 0, n - 1);
        return ans;
    }
    Node* buildTree(vector<int>& in, vector<int>& pre)
    {
        // return approach_1(in, pre); // Traversing and partitioning inorder
        return approach_2(in, pre); // Using Hash set and partitioning inorder
    }
};

//{ Driver Code Starts.
// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends