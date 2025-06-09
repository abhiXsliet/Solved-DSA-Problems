// https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1




#include <bits/stdc++.h>
using namespace std;

/*The Node structure is */
class Node
{
    public:
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  private:
    void solve(Node *root, unordered_set<int> &st, vector<int> &leafs) {
        if (!root) return;
        if (!root -> left && !root -> right) {
            leafs.push_back(root -> data);
        }
        st.insert(root -> data);
        solve(root ->  left, st, leafs);
        solve(root -> right, st, leafs);
    }
    
    // TC : O(N)
    // SC : O(N)
    bool brute(Node *root) {
        vector<int> leafs;
        unordered_set<int> st;
        st.insert(0);
        solve(root, st, leafs);
        for (int &leaf : leafs) {
            if (st.count(leaf - 1) && st.count(leaf + 1)) 
                return true;
        }
        return false;
    }
    
    // TC : O(N)
    // SC : O(H)
    bool optimal(Node *root, int mini, int maxi) {
        if (!root) return 0;
        if (!root -> left && !root -> right) {
            return ((root -> data - mini == 1) && (maxi - root -> data ==1));
        }
        
        bool L = optimal(root ->  left, mini, root -> data);
        bool R = optimal(root -> right, root -> data, maxi);
        return L || R;
    }
  public:
    bool isDeadEnd(Node *root) {
        // return brute(root);
        return optimal(root, 0, INT_MAX);
    }
};