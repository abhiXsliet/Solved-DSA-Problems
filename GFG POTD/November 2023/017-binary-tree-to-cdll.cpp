// https://www.geeksforgeeks.org/problems/binary-tree-to-cdll/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



void displayCList(Node *head)
{
    Node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout <<endl;
    itr=itr->left;
    head = itr;
    do{
        cout<<itr->data<<" ";
        itr=itr->left;
    }while(head!=itr);
    cout<<endl;
}

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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
  private:
    // TC = O(N)
    // SC = O(N + H) -> Recursive depth + to store the nodes
    void inorder(Node* root, vector<Node*>& store) {
        if (root == NULL)
            return;
            
        inorder(root -> left, store);
        store.push_back(root);
        inorder(root -> right, store);
    }
    
    // TC = O(N)
    // SC = O(N + H)
    Node* solve_brute(Node* root) {
        Node* head = NULL;
        Node* prev = NULL;
        
        vector<Node*> store;
        
        inorder(root, store);
        
        int n = store.size();
        
        for (int i = 0; i < n; i++) {
            Node* curr = store[i];
            
            if (head == NULL) {
                head = prev = curr;
            }
            else {
                prev -> right = curr;
                curr -> left  = prev;
            }
            
            //update the prev
            prev = curr;
        }
        
        // to maintain the circular nature
        head -> left  = prev;
        prev -> right = head;
        
        return head;
    }
    
    // TC = O(N)
    // SC = O(H) -> Recursive Depth
    void inorder_inplace(Node* root, Node* &head, Node* &prev) {
        if (root == NULL)
            return;
        
        inorder_inplace(root -> left, head, prev);
        
        if (head == NULL) {
            head = prev = root;
        }
        else {
            prev -> right = root;
            root -> left  = prev;
        }
        
        // update the prev
        prev = root;
        
        inorder_inplace(root -> right, head, prev);
    }
    
    // TC = O(N)
    // SC = O(H)
    Node* solve_optimal(Node* root) {
        Node* head = NULL;
        Node* prev = NULL;
        
        inorder_inplace(root, head, prev);
        
        // to maintain the circular nature of LL
        head -> left  = prev;
        prev -> right = head;
        
        return head;
    }
    
  public:
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {
        // return solve_brute(root);
        
        return solve_optimal(root);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution obj;
        Node *head = obj.bTreeToCList(root);
        displayCList(head);
    }
    return 0;
}
// } Driver Code Ends