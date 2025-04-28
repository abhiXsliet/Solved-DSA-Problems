// https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1




//{ Driver Code Starts
// Initial Template for C++
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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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
// User function Template for C++

// Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  private:
    using P = pair<int, int>;
    map<pair<bool, Node*>, int> mpp;
    
    
    // TC : O(N)
    // SC : O(H)
    P solve(Node* root) {
        if (!root) {
            return {0, 0};  // {include, exclude}
        }
        
        P L = solve(root ->  left);
        P R = solve(root -> right);
        
        int include = root -> data + L.second + R.second;
        int exclude = max(L.first, L.second) + max(R.first, R.second);
        
        return {include, exclude};
    }
    
    int f(bool canPick, Node* root) {
        if (!root) return 0;
        
        pair<bool, Node*> key = {canPick, root};
        if (mpp.count(key))
            return mpp[key];

        int pick = 0;
        if (canPick) {
            pick = root -> data + f(0, root -> left) + f(0, root -> right);
        }
        int notPick = f(1, root -> left) + f(1, root -> right);
        
        return mpp[key] = max(pick, notPick);
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    int approach_1(Node* root) {
        return f(1, root);
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_2(Node* root) {
        P it = solve(root);
        return max(it.first, it.second);
    }
  public:
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        // return approach_1(root);
        return approach_2(root);
    }
};


//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.getMaxSum(root) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends