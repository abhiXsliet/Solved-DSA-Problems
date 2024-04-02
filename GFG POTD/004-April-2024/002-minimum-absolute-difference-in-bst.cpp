// https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};
// Utility function to create a new Tree Node
Node *newNode(int val)
{
  Node *temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}
// Function to Build Tree
Node *buildTree(string str)
{
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
  Node *root = newNode(stoi(ip[0]));

  // Push the root to the queue
  queue<Node *> queue;
  queue.push(root);

  // Starting from the second element
  int i = 1;
  while (!queue.empty() && i < ip.size())
  {

    // Get and remove the front of the queue
    Node *currNode = queue.front();
    queue.pop();

    // Get the current node's value from the string
    string currVal = ip[i];

    // If the left child is not null
    if (currVal != "N")
    {

      // Create the left child for the current node
      currNode->left = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->left);
    }

    // For the right child
    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];

    // If the right child is not null
    if (currVal != "N")
    {

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
/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

};
*/

class Solution
{
    private:
    // TC : O(N)
    // SC : O(H) -> Recursive Depth
    void inorder(Node* root, vector<int>& storeInorder) {
        if (!root) return;

        inorder(root -> left , storeInorder);
        storeInorder.push_back(root -> data);
        inorder(root -> right, storeInorder);
    }
    
    // TC : O(N)
    // SC : O(N)
    int solve_brute(Node* root) {
        vector<int> storeInorder;
        inorder(root, storeInorder);
        int ans = INT_MAX;
        for (int i = 1; i < storeInorder.size(); i++) {
            int diff = storeInorder[i] - storeInorder[i - 1];
            ans = min(ans, diff);
        }
        return ans;
    }
    // TC : O(N)
    // SC : O(H) -> Recursive Depth
    void func(Node* root, int& ans, int& prev) {
        if (!root) return;

        func(root -> left , ans, prev);
        if (prev != -1) {
            ans = min(ans, root -> data - prev);
        }
        prev = root -> data;
        func(root -> right, ans, prev);
    }
    
    // TC : O(N)
    // SC : O(1)
    int solve_optimal(Node* root) {
        int ans  = INT_MAX;
        int prev = -1;
        func(root, ans, prev);
        return ans;
    }
    public:
    int absolute_diff(Node *root)
    {
        // return solve_brute(root);
        
        return solve_optimal(root);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        if (root == NULL)
        continue;
        if (root->left == NULL and root->right == NULL)
        continue;
        Solution ob;
        cout << ob.absolute_diff(root) << '\n';
    }
    return 1;
}
// } Driver Code Ends