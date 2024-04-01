// https://www.geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

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

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  private:
    int merge(vector<int>& store, int start, int mid, int end) {
        vector<int> temp;
        int cnt = 0;
        int l = start, r = mid + 1;
        while(l <= mid && r <= end) {
            if (store[l] <= store[r]) {
                temp.push_back(store[l]);
                l ++;
            }
            else {  // cnt Inversion since 1st half is greater than 2nd half
                cnt += (mid - l + 1);
                temp.push_back(store[r]);
                r ++;
            }
        }
        
        while (l <= mid) {
            temp.push_back(store[l]);
            l ++;
        } 
        
        while (r <= end) {
            temp.push_back(store[r]);
            r ++;
        }
        
        for (int i = start; i <= end; i++) {
            store[i] = temp[i - start];
        }
        return cnt;
    }
    int mergeSort(vector<int>& store, int start, int end) {
        int cnt = 0;
        if (start >= end) return 0;
        
        int mid = start + (end - start) / 2;
        
        cnt += mergeSort(store, start, mid);
        cnt += mergeSort(store, mid + 1, end);
        cnt += merge(store, start, mid, end);
        
        return cnt;
    }
    int countInversion(vector<int>& store) {
        int n   = store.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (store[i] > store[j]) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
    void inorder(Node* &root, vector<int>& store) {
        if(!root) return;
        
        inorder(root -> left , store);
        store.push_back(root -> data);
        inorder(root -> right, store);
    }
    
    // TC : O(N^2)
    // SC : O(N)
    int solve_brute(Node* &root) {
        vector<int> store;
        inorder(root, store);
        return countInversion(store);
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    int solve_optimal(int n, Node* &root) {
        vector<int> store;
        inorder(root, store);
        return mergeSort(store, 0, n - 1);
    }
  public:
    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        // return solve_brute(root);
        
        return solve_optimal(n, root);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends