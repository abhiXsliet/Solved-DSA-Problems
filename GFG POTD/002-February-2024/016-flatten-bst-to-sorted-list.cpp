// https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1



//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *newNode(int key)
{
    Node *node = new Node(key);
    return node;
}

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

void printList(Node *head)
{
    while (head)
    {
        if(head->left)
            cout<<"-1 ";
        cout << head->data << " ";
        head = head->right;
    }
    cout << "\n";
}


// } Driver Code Ends
//User function Template for C++

/* Node of the binary search tree 
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
private:
    // TC : O(N)
    // SC : O(H) -> Depth Of Recursive Height
    void solve(Node* root, vector<Node*>& store) {
        if (!root) return;
        
        solve(root -> left , store);
        store.push_back(root);
        solve(root -> right, store);
    }
    
    // TC : O(N)
    // SC : O(N)   
    Node* way_1(Node* root) {
        vector<Node*> store;
        solve(root, store);
        Node* newNode = new Node(-1);
        Node* ans     = newNode;
        for (auto& it : store) {
            newNode -> right = it;
            newNode -> left  = NULL;
            newNode = newNode -> right;
        }
        newNode -> left = NULL;
        return ans -> right;
    }
    
    // TC : O(N)
    // SC : O(H) -> Depth Of Recursive Height
    void inorder(Node* root, vector<int>& store) {
        if (!root) return;
        
        inorder(root -> left , store);
        store.push_back(root -> data);
        inorder(root -> right, store);
    }
    
    // TC : O(N)
    // SC : O(N)   
    Node* way_2(Node* root) {
        vector<int> store;
        inorder(root, store);
        Node* newNode = new Node(-1);
        Node* ans     = newNode;
        for (auto& it : store) {
            newNode -> right = new Node(it);
            newNode = newNode -> right;
        }
        return ans -> right;
    }
public:
    Node *flattenBST(Node *root)
    {
        // return way_1(root);
        
        return way_2(root);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        Solution ob;
        auto ans = ob.flattenBST(root);
        printList(ans);
    }
    return 0;
}


// } Driver Code Ends