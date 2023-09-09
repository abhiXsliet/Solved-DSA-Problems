// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1



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
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
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
/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    private:
    void inorder(Node* &root, vector<int>& store) {
        if (root == NULL) return;
        
        inorder(root -> left, store);
        store.push_back(root-> data);
        inorder(root -> right, store);
    }
    
    void reverseInorder(Node* root, int& k, int& result) {
        if (!root || k == 0) return;
        
        reverseInorder(root -> right, k, result);
        k--;
        if(k == 0) {
            result = root -> data;
            return;
        }
        
        reverseInorder(root -> left, k, result);
    }
    
    // Extra Space, i.e., O(N) where n = no. of nodes
    int solve_brute(Node *root, int k) {
        vector<int> store;
        inorder(root, store);
        return store[store.size()-k];
    }
    
    // No Extra Space only space due to recursive call stack (O(H))
    int solve_optimal(Node *root, int k) {
        int result = -1;
        reverseInorder(root, k, result);
        return result;
    }
    
    public:
    int kthLargest(Node *root, int k)
    {
        // return solve_brute(root, k);
        
        return solve_optimal(root, k);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int k;
        cin>>k;
        getchar();
        
        Solution ob;
        cout << ob.kthLargest( head, k ) << endl;
    }
    return 1;
}
// } Driver Code Ends