// https://www.geeksforgeeks.org/problems/kth-common-ancestor-in-bst/1



//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// A Tree node
struct Node
{
	int data;
	struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return (temp);
}

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
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
//User function Template for C++

/*// A Tree node
struct Node
{
	int data;
	struct Node *left, *right;
};*/

class Solution
{
    private:
    // TC : O(H)
    // SC : O(H) Where H : Height of Tree
    int get_lca_fast(Node* root, int x, int y) {
        while(root != NULL) {
            if (root -> data > x && root -> data > y) {
                root = root -> left;
            }
            else if (root -> data < x && root -> data < y) {
                root = root -> right;
            }
            else break;
        }
        return root -> data;
    }
    
    // TC : O(N)
    // SC : O(H) -> Recursive Depth
    int get_lca(Node* root, int x, int y) {
        if (!root) return NULL;
        
        if (root -> data == x || root -> data == y) {
            return root -> data;
        }
        
        int leftCall  = get_lca(root -> left , x, y);
        int rightCall = get_lca(root -> right, x, y);
        
        if (!leftCall && rightCall) {
            return rightCall;
        }
        else if (leftCall && !rightCall) {
            return leftCall;
        }
        else if (leftCall && rightCall) {
            return root -> data;
        }
        return NULL;
    }
    
    // TC : O(N)
    // SC : O(H) + O(N)
    // Works on all trees including bst
    void store_path(Node* root, vector<int>& path, int node) {
        if (!root) return;
        
        path.push_back(root -> data);
        if (root -> data == node) return;
        
        store_path(root -> left, path, node);
        if (path.back() == node) return;
        
        store_path(root -> right, path, node);
        if (path.back() == node) return;
        
        path.pop_back();
    }
    
    // TC : O(log(N))
    // SC : O(N)
    // Works on BST Only
    void store_path_2(Node* root, vector<int>& path, int node) {
        while(root != NULL) {
            path.push_back(root -> data);
            if (root -> data == node) 
                return;
            else if (root -> data < node) {
                root = root -> right;
            }
            else {
                root = root -> left;
            }
        }
    }
    
    // TC : O(N)
    // SC : O(N)
    int solve_approach_1(Node* root, int &k, int x, int y) {
        vector<int>path1;
        vector<int>path2;
        
        // store_path(root, path1, x);
        // store_path(root, path2, y);
        
        store_path_2(root, path1, x);
        store_path_2(root, path2, y);
        
        int m = path1.size();
        int n = path2.size();
        int i = min(m, n) - 1;
         
        while (i >= 0) {
            if (path1[i] == path2[i]) {
                if (k == 1) {
                    return path1[i];
                }
                k --;
            }
            i --;
        }
        
        return -1;
    }
    
    // TC : O(N)
    // SC : O(N)
    int solve_approach_2(Node* root, int &k, int x, int y) {
        int lca = get_lca(root, x, y);
        // stores the common ancestor nodes till lca
        vector<int>common_anc;
        // store_path(root, common_anc, lca);
        store_path_2(root, common_anc, lca);
        
        int n = common_anc.size();
        return (n - k < 0) ? -1 : common_anc[n - k];
    }
    
    // TC : O(H) + O(log(N)) ~= O(H)
    // SC : O(H) Where H = Height of Tree
    int solve_approach_3(Node* root, int &k, int x, int y) {
        int lca = get_lca_fast(root, x, y);
        // stores the common ancestor nodes till lca
        vector<int>common_anc;
        // store_path(root, common_anc, lca);
        store_path_2(root, common_anc, lca);
        
        int n = common_anc.size();
        return (n - k < 0) ? -1 : common_anc[n - k];
    }
    public:
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // return solve_approach_1(root, k, x, y);
        
        // return solve_approach_2(root, k, x, y);
        
        return solve_approach_3(root, k, x, y);
    }
};


//{ Driver Code Starts.
int main ()
{
	int t;
	cin >> t;
	cin.ignore();

	while (t--)
	{
	
		string inp;
		getline(cin, inp);
		
		int k,x,y;
		cin>>k>>x>>y;
		cin.ignore();

		struct Node* root = buildTree(inp);

        Solution ob;
		int ans = ob.kthCommonAncestor(root,k,x,y);
		cout<<ans<<endl;

	}

	return 0;
}
// } Driver Code Ends