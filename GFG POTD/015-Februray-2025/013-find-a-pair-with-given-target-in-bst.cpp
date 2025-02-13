// https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000
#define MAX_SIZE 100000

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
/*
Node is as follows
class Node {
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
    void pushLeft(Node *root, stack<Node*> &leftStk) {
        while (root) {
            leftStk.push(root);
            root = root -> left;
        }
    }
    
    void pushRight(Node *root, stack<Node*> &rightStk) {
        while (root) {
            rightStk.push(root);
            root = root -> right;
        }
    }
    
    bool solve(Node *root, int target, unordered_set<int>& st) {
        if (!root) return false;
        
        int required = target - (root -> data);
        if (st.count(required)) {
            return true;
        } else {
            st.insert(root -> data);
        }
        
        return solve(root ->  left, target, st) |
               solve(root -> right, target, st);
    }
        
    // TC : O(N)
    // SC : O(N)
    bool approach_1(Node *root, int target) {
        unordered_set<int> st;
        return solve(root, target, st);
    }
    
    // TC : O(N)
    // SC : O(H)
    bool approach_2(Node *root, int target) {
        stack<Node*> leftStk, rightStk;
        
        pushLeft(root, leftStk);
        pushRight(root, rightStk);
        
        while (!leftStk.empty() && !rightStk.empty()) {
            if (leftStk.top() == rightStk.top()) // root node
                break;
            
            int sum = (leftStk.top() -> data) + (rightStk.top() -> data);
            
            if (sum == target) 
                return true;
            else if (sum < target) {
                Node* topNode = leftStk.top();
                leftStk.pop();
                pushLeft(topNode -> right, leftStk);
                
            } else if (sum > target) {
                Node* topNode = rightStk.top();
                rightStk.pop();
                pushRight(topNode -> left, rightStk);
            }
        }
        return false;
    }
  public:
    bool findTarget(Node *root, int target) {
        // BRUTE : store Inorder -> Use two ptr (two sum)
        
        // return approach_1(root, target);    // Using Hash Set
        return approach_2(root, target);    // Inorder Traversal with Two Stacks
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        getline(cin, s);
        int k = stoi(s);
        // getline(cin, s);
        Solution obj;
        cout << obj.findTarget(root, k) << endl;
        // cout<<"~"<<endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends