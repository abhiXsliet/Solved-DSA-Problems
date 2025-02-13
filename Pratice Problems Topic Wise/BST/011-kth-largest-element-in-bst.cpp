// https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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
class Solution {
  private:
    int ans = -1;
    void solve_2(Node *root, int &k) {
        if (!root) return;
        solve_2(root -> right, k);
        k --;
        if (k == 0) {
            ans = root -> data;
            return;
        }
        solve_2(root ->  left, k);
    }
    
    int solve_1(Node *root, int &k) {
        if (!root) return -1;
        
        int right = solve_1(root -> right, k);
        if (right != -1) return right;
        
        k --;
        if (k == 0) return root -> data;
        
        return solve_1(root -> left, k);
    }
    
    // TC : O(N)
    // SC : O(H)
    int way_1(Node *root, int k) {
        return solve_1(root, k);
    }
    
    // TC : O(N)
    // SC : O(H)
   
    int way_2(Node *root, int k) {
        solve_2(root, k);  // Inorder in reverse
        return ans;
    }
  public:
    int kthLargest(Node *root, int k) {
        return way_1(root, k);
        // return way_2(root, k);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string s;
        getline(cin, s);
        Node* head = buildTree(s);

        int k;
        cin >> k;
        getchar();

        Solution ob;
        cout << ob.kthLargest(head, k) << endl;

        cout << "~"
             << "\n";
    }
    return 1;
}
// } Driver Code Ends