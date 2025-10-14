// https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1/




#include <bits/stdc++.h>
using namespace std;

// Node Structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
  private:
    using P = pair<int, int>;
    map<pair<bool, Node*>, int> mpp;

    P solve(Node* root) {
        if (!root) {
            return {0, 0};  // {include, exclude}
        }
        
        P L = solve(root ->  left);
        P R = solve(root -> right);
        
        int include = root -> data + L.second + R.second;
        int exclude = max(L.first, L.second) + max(R.first, R.second);
        
        return {include, exclude};
    }
    
    int f(bool canPick, Node* root) {
        if (!root) return 0;
        
        pair<bool, Node*> key = {canPick, root};
        if (mpp.count(key))
            return mpp[key];

        int pick = 0;
        if (canPick) {
            pick = root -> data + f(0, root -> left) + f(0, root -> right);
        }
        int notPick = f(1, root -> left) + f(1, root -> right);
        
        return mpp[key] = max(pick, notPick);
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    int approach_1(Node* root) {
        return f(1, root);
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_2(Node* root) {
        P it = solve(root);
        return max(it.first, it.second);
    }
  public:
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        // return approach_1(root);
        return approach_2(root);
    }
};