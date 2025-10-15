// https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1/




#include <bits/stdc++.h>
using namespace std;

/*Complete the function below*/
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  private:
    // TC : O(N)
    // SC : O(H)
    void inorder(Node *root, vector<int>& store) {
        if (!root) return;
        inorder(root ->  left, store);
        store.push_back(root -> data);
        inorder(root -> right, store);
    }
    
    // TC : O(N)
    // SC : O(N)
    int approach_1(Node *root, int k) {
        vector<int> storeInorder;
        inorder(root, storeInorder);
        return k > storeInorder.size() ? -1 : storeInorder[k - 1];
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_2(Node *root, int &k) {
        if (!root) return -1;

        int left = approach_2(root->left, k);
        if (left != -1) return left;
    
        k--;
        if (k == 0) return root->data;
    
        return approach_2(root->right, k);
    }
  public:
    int kthSmallest(Node *root, int k) {
        // return approach_1(root, k);
        return approach_2(root, k);
    }
};