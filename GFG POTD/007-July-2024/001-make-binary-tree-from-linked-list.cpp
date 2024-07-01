// https://www.geeksforgeeks.org/problems/make-binary-tree/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {

    struct Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void lvl(TreeNode *r) {
    if (r == NULL)
        return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left)
            q.push(j->left);
        if (j->right)
            q.push(j->right);
    }
}

void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    void getNodeData(vector<int>& store, Node* head) {
        while(head) {
            store.push_back(head -> data);
            head = head -> next;
        }
    }
    
    // TC : O(N)
    // SC : O(N) Recursive Depth
    void buildTree(TreeNode* &root, int i, vector<int>& store) {
        if (i >= store.size()) return;
        
        root = new TreeNode(store[i]);
        buildTree(root -> left , 2*i + 1, store);
        buildTree(root -> right, 2*i + 2, store);
    }
    
    // TC : O(N)
    // SC : O(N)
    void way_1(Node* head, TreeNode* &root) {
        vector<int> store;
        getNodeData(store, head);
        buildTree(root, 0, store);
    }
  public:
    void convert(Node *head, TreeNode *&root) {
        way_1(head, root);
    }
};

//{ Driver Code Starts.
int main() {
    int T, i, n, l, k;

    cin >> T;

    while (T--) {
        struct Node *head = NULL;

        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> l;
            push(&head, l);
        }
        reverses(&head);
        Node *prevhead = head;
        TreeNode *root = NULL;
        Solution obj;

        obj.convert(head, root);
        if (root == NULL) {
            cout << "-1\n";
        } else if (root == NULL && prevhead != NULL) {
            cout << "-1\n";
        } else {
            lvl(root);
            cout << endl;
        }
        // inorder(root);
        getchar();
    }
    return 0;
}
// } Driver Code Ends