// https://www.geeksforgeeks.org/problems/k-sum-paths/1



//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
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
//User function template for C++

/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
  private:
    int mod=1e9+7;
    
    void solve_1(Node* root, int k, vector<int>& path, int& cnt) {
        if (root == NULL) 
            return;
        
        path.push_back(root -> data);
        
        solve_1(root -> left , k, path, cnt);
        solve_1(root -> right, k, path, cnt);
        
        int sum = 0;
        int m = path.size();
        for (int i = m - 1; i >= 0; i--) {
            sum += path[i];
            if (sum == k) cnt++;
        }
        
        path.pop_back();
    }
    
    void solve_2(Node* root, int k, int sum, int& ans, unordered_map<int, int>& mpp) {
        if(!root) return;
        
        sum += root->data;
        ans += mpp[sum-k];
        mpp[sum]++;
        
        solve_2(root->left , k, sum, ans, mpp);
        solve_2(root->right, k, sum, ans, mpp);
        
        mpp[sum]--;
    }
    
    // TLE
    // TC = O(N^2)
    // SC = O(N)
    int solve_approach_1(Node* root, int k) {
        vector<int> path;
        int cnt = 0;
        solve_1(root, k, path, cnt);
        return cnt;
    }
    
    // TC = O(N)
    // SC = O(N)
    int solve_approach_2(Node* root, int k) {
        unordered_map<int, int>mpp;
        int ans=0;
        mpp[0]=1;
        solve_2(root, k, 0,ans, mpp);
        return ans;
    }
  public:
    int sumK(Node *root, int k)
    {
        // return solve_approach_1(root, k);
        
        return solve_approach_2(root, k);
    }
};


//{ Driver Code Starts.

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);
  
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        string key;
        getline(cin, key);
        int k=stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends