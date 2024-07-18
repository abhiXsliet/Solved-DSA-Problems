// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/




#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void makeGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>& adj, 
                    unordered_set<TreeNode*>& st) {
        
        if (!root) return;
        if (!root -> left && !root -> right)    // a leaf node
            st.insert(root);

        if (prev != NULL) {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }
        
        makeGraph(root -> left , root, adj, st);
        makeGraph(root -> right, root, adj, st);
    }

    vector<int> solve(TreeNode* root, int dist, int& leafPairsCnt) {
        if (!root) return {};
        if (root -> left == NULL && root -> right == NULL) return {1};

        auto left  = solve(root -> left , dist, leafPairsCnt);
        auto right = solve(root -> right, dist, leafPairsCnt);
       
        vector<int> store;
        for (auto a : left)  {
            if (a + 1 < dist)  // slight optimzation   
                store.push_back(a + 1);
        }
        for (auto b : right)  {
            if (b + 1 < dist)  // slight optimzation   
                store.push_back(b + 1);
        }

        for (auto a : left) {
            for (auto b : right) {
                if (a + b <= dist) 
                    leafPairsCnt ++;
            }
        }
        return store;
    }

    // TC : O(N^2) 
    // SC : O(N) Where 'N' is the number of nodes in the tree
    int way_1(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> st;    // stores leaf nodes

        // already connected prev node (1) to curr node (2) : 1 -> 2
        // now we have to connect curr node (2) to prev (1) : 2 -> 1
        makeGraph(root, NULL, adj, st);

        int leafPairsCnt = 0;   // no. of pairs of leaf whose shortest dist <= D

        // TC : total leaf nodes proportional to O(N) * Hitting BFS from each leaf node O(N)
        for (TreeNode* leaf : st) {  // Hit BFS from each leaf node and find another leaf within distance
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;
            q.push(leaf);
            visited.insert(leaf);

            for (int level = 0; level <= distance; level ++) {  // slight optimization : only go level till <= distance
                int size = q.size();
                while (size --) {
                    TreeNode* currNode = q.front();
                    q.pop();

                    if (currNode != leaf && st.count(currNode)) {
                        leafPairsCnt ++;
                    }

                    for (TreeNode* &nbr : adj[currNode]) {
                        if (!visited.count(nbr)) {
                            q.push(nbr);
                            visited.insert(nbr);
                        }
                    }
                }
            }
        }
        return leafPairsCnt / 2;    // since leaf node (4, 5) & (5, 4) are same
    }

    // TC : O(N) It will not be Quadratic because the max distance given is 10
    // SC : O(N) Where 'N' is the number of nodes in the tree
    int way_2(TreeNode* root, int distance) {
        int leafPairsCnt = 0;
        solve(root, distance, leafPairsCnt);
        return leafPairsCnt;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        // return way_1(root, distance);    // As Per Hint (using BFS : level order traversal)

        return way_2(root, distance);   // store distances from left and right to its parent in a vector
                                           // then sum (leftDist[i] + rightDist[i] <= D) so, leafPairsCnt += 1 whose dist b/w pairs is <= D
    }
};