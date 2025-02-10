// https://www.geeksforgeeks.org/problems/k-sum-paths/1




//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

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
/*
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

class Solution { 
  private:
    // TC : O(N)
    // SC : O(H)
    int getCountOfPaths(Node *root, int k, int currSum) {
        if (!root) return 0;
        
        int pathCount = 0;
        
        currSum += root -> data;
        if (currSum == k) pathCount ++;

        int L = getCountOfPaths(root ->  left, k, currSum);
        int R = getCountOfPaths(root -> right, k, currSum);
        
        return pathCount + L + R;
    }

    // TC : O(N^2)
    // SC : O(1)
    int brute(Node *root, int k) {
        if (!root) return 0;
        // count all paths whose sum == k from root
        int paths = getCountOfPaths(root, k, 0);
        
        // count all paths whose sum == k for root -> left (Recursively)
        int L = brute(root ->  left, k);
        
        // count all paths whose sum == k for root -> left (Recursively)
        int R = brute(root -> right, k);
        
        return paths + L + R;
    }
    
    // TC : O(N)
    // SC : O(H) Due to recursive depth
    int optimal(Node *root, int k, unordered_map<int, int> &mpp, int currSum) {
        if (!root) return 0;
        
        int pathCount = 0;
        
        currSum += root -> data;

        pathCount += mpp[currSum - k];
        mpp[currSum] += 1;
        
        int L = optimal(root ->  left, k, mpp, currSum);
        int R = optimal(root -> right, k, mpp, currSum);
        
        mpp[currSum] -= 1;
        
        return pathCount + L + R;
    }
  public:
    int sumK(Node *root, int k) {
        // return brute(root, k);   // Try making pathSum == k from every node
        
        unordered_map<int, int> mpp;  // track the currSum till a node with its occurances
        mpp[0] = 1;
        return optimal(root, k, mpp, 0);
    }
};


//{ Driver Code Starts.
int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);

    while (t--) {
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);

        string key;
        getline(cin, key);
        int k = stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends