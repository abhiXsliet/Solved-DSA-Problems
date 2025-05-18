// https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after splitting by space
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

/* A binary tree node has data, pointer to left child
   and a pointer to right child
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  private:
    // TC : O(N)
    // SC : O(N) : highest nodes in a level = 2^h - 1
    vector<int> approach_1(Node* root) {
        vector<int> result;
        queue<Node*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> levelNodes;
            while (n --) {
                Node *fNode = q.front();
                q.pop();
                
                levelNodes.push_back(fNode -> data);
                
                if (fNode -> left) {
                    q.push(fNode -> left);
                }
                if (fNode -> right) {
                    q.push(fNode -> right);
                }
            }
            // odd level  -> left  to right
            if (level % 2) {
                for (int i = 0; i < levelNodes.size(); i ++) {
                    result.push_back(levelNodes[i]);
                }
            } else {// even level -> right to left
                for (int i = levelNodes.size() - 1; i >= 0; i --) {
                    result.push_back(levelNodes[i]);
                }
            }
            level += 1;
        }
        return result;
    }

    void dfs(Node* root, int level, vector<vector<int>>& levels) {
        if (!root) return;
        
        if (level >= levels.size()) {
            levels.push_back({});
        }
        
        levels[level].push_back(root->data);
        
        dfs(root->left, level + 1, levels);
        dfs(root->right, level + 1, levels);
    }
    
    // TC : O(N)
    // SC : O(N)
    vector<int> approach_2(Node* root) {
        vector<vector<int>> levels;
        dfs(root, 0, levels);
        
        vector<int> result;
        for (int i = 0; i < levels.size(); ++i) {
            if (i % 2 == 1) {
                // Odd level: left to right (already in order)
                result.insert(result.end(), levels[i].begin(), levels[i].end());
            } else {
                // Even level: right to left (reverse before adding)
                reverse(levels[i].begin(), levels[i].end());
                result.insert(result.end(), levels[i].begin(), levels[i].end());
            }
        }
        
        return result;
    }
  public:
    vector<int> findSpiral(Node* root) {
        // return approach_1(root);     // BFS
        
        return approach_2(root);     // DFS
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    Solution sol; // Create Solution object
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        // Call the findSpiral function from Solution class
        vector<int> vec = sol.findSpiral(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends