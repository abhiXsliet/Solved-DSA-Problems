// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
// } Driver Code Ends

/* A binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  private:
    void dfs(Node *root, int level, vector<int> &result) {
        if (!root) return;
        
        if (result.size() == level) {
            result.push_back(root -> data);
        }
        
        dfs(root ->  left, level + 1, result);
        dfs(root -> right, level + 1, result);
    }
    
    // TC : O(N)
    // SC : O(1)
    vector<int> approach_1(Node *root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }
    
    // TC : O(N)
    // SC : O(N)
    vector<int> approach_2(Node *root) {
        vector<int> result;
        if (!root) return result;
        
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            result.push_back(q.front() -> data);
            while (n --) {
                Node* fNode = q.front();
                q.pop();
                
                if (fNode ->  left) q.push(fNode -> left);
                if (fNode -> right) q.push(fNode -> right);
            }
        }
        return result;
    }
  public:
    vector<int> leftView(Node *root) {
        // return approach_1(root);    // DFS
        return approach_2(root);    // BFS
    }
};

//{ Driver Code Starts.
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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> vec = ob.leftView(root);
        if (vec.size() == 0) {
            cout << "[]";
        }
        for (int x : vec)
            cout << x << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends