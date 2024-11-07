// https://www.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
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

// } Driver Code Ends
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution
{
public:
    void inorder(Node *root, int num, vector<int> &vec)
    {
        if (root == nullptr)
        {

            return;
        }
        num = num * 10 + root->data;
        if (root->left == nullptr && root->right == nullptr)
        {
            vec.push_back(num);
        }
        inorder(root->left, num, vec);

        inorder(root->right, num, vec);
    }
    int treePathsSum(Node *root)
    {
        vector<int> vec;
        int num = 0;
        int sum = 0;
        inorder(root, num, vec);
        for (auto it : vec)
        {
            sum += it;
        }
        return sum;
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
        Solution ob;
        cout << ob.treePathsSum(root);
        cout << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends