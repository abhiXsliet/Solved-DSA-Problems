// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/



#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    typedef long long ll;

    // TC : O(N*log(K))
    // SC : O(N)
    void levelOrderTraversal(TreeNode* root, int k, priority_queue<ll, vector<ll>, greater<ll>>& pq) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            ll sum = 0;
            while (size --) {
                TreeNode* ele = q.front();
                q.pop();

                sum += (ele -> val);

                if (ele -> left)  q.push(ele -> left);
                if (ele -> right) q.push(ele -> right);
            }
            pq.push(sum);
            if (pq.size() > k) pq.pop();
        }
    }

    // TC : O(N)
    // SC : O(N)
    void solve(TreeNode* root, vector<ll>& store) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            ll sum = 0;
            while (size --) {
                TreeNode* ele = q.front();
                q.pop();
                sum += (ele -> val);

                if (ele -> left)  q.push(ele -> left);
                if (ele -> right) q.push(ele -> right);
            }
            store.push_back(sum);
        }
    }

    // TC : O(N * log(N))
    // SC : O(N)
    ll approach_1(TreeNode* root, int k) {
        vector<ll> storeSum;
        solve(root, storeSum);
        sort(rbegin(storeSum), rend(storeSum));
        return k <= storeSum.size() ? storeSum[k - 1] : -1;
    }

    // TC : O(N * log(K))
    // SC : O(N)
    ll approach_2(TreeNode* root, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        levelOrderTraversal(root, k, pq);
        return pq.size() < k ? -1 : pq.top();
    }
public:
    ll kthLargestLevelSum(TreeNode* root, int k) {
        return approach_1(root, k); // Store each level sum using LevelOrderTraversal & then sort and return it
        return approach_2(root, k); // Using MinHeap   
    }
};