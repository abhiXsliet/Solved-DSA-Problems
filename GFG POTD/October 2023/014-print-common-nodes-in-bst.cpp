// https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1



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


class Solution
{
    private:
    void inorder(Node* root1, set<int>& store) {
        if (root1 == NULL) return;
        
        inorder(root1 -> left, store);
        store.insert(root1 -> data);
        inorder(root1 -> right, store);
    }
    
    void inorder_push(Node* root2, vector<int>& result, set<int>& store) {
        if (root2 == NULL) return;
        
        inorder_push(root2 -> left, result, store);
        if (store.find(root2 -> data) != store.end())
            result.push_back(root2 -> data);
        inorder_push(root2 -> right, result, store);
    }
    
    // TC = O(2*N)   ~ O(N)
    // SC = O(H + N) ~ O(N)
    vector<int> solve_brute(Node *root1, Node *root2) {
        vector<int> result;
        set<int> store;
        
        inorder(root1, store);
        inorder_push(root2, result, store);
        
        return result;
    }
    
    // TC = O(N1 + N2)
    // SC = O(H1 + H2)
    vector<int> solve_optimal(Node *root1, Node *root2) {
        stack<Node*> s1;
        stack<Node*> s2;
        vector<int> ans;
        
        while(1) {
            if (root1 != NULL) {
                s1.push(root1);
                root1 = root1 -> left;
            }
            else if (root2 != NULL) {
                s2.push(root2);
                root2 = root2 -> left;
            }
            else if (!s1.empty() && !s2.empty()) {
                root1 = s1.top();
                root2 = s2.top();
                
                // pop smaller and move right
                if (root1 -> data == root2 -> data) {
                    ans.push_back(root1 -> data);
                    
                    s1.pop();
                    s2.pop();
                    
                    root1 = root1 -> right;
                    root2 = root2 -> right;
                }
                else if (root1 -> data < root2 -> data) {
                    s1.pop();
                    root1 = root1 -> right;
                    root2 = NULL;
                }
                else if (root1 -> data > root2 -> data) {
                    s2.pop();
                    root2 = root2 -> right;
                    root1 = NULL;
                }
            }
            else 
                break; //one of the stack becomes empty
        }
        return ans;
    }
    
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        // return solve_brute(root1, root2);
        
        return solve_optimal(root1, root2);
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
        Node* root1 = buildTree(s);

        getline(cin,s);
        Node* root2 = buildTree(s);
        Solution ob;
        vector <int> res = ob.findCommon(root1, root2);
        for (int i : res)
            cout << i << " ";
        cout<< endl;
    }

	return 1;
}
// } Driver Code Ends