// https://leetcode.com/problems/fruits-into-baskets-iii/




#include <bits/stdc++.h>
using namespace std;

class SGT {
public:
    vector<int> segTree;
    SGT(int n) {
        segTree.resize(4*n, 0);
    }

    void buildSegTree(int i, int l, int r, vector<int> &arr) {
        if (l == r) {
            segTree[i] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegTree(2 * i + 1, l, mid, arr);
        buildSegTree(2 * i + 2, mid + 1, r, arr);

        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    // This function searches for a target value, consumes it, and updates the tree
    int search(int tar, int i, int l, int r) {
        if (tar > segTree[i]) return -1;    // Target is greater than the maximum in this range
        if (l == r) {   // Leaf node: consume the value
            int val = segTree[i];
            segTree[i] = INT_MIN;   // Mark as used
            return val; // Return the consumed value
        }

        int mid = l + (r - l) / 2;
        // Search in the left or right subtree based on the target value
        int foundIdx = (tar <= segTree[2 * i + 1]) ? search(tar, 2 * i + 1, l, mid) : search(tar, 2 * i + 2, mid + 1, r);
        // Update the current node with the maximum of its children
        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);  
        
        return foundIdx;    // Return the consumed value
    }
};

class Solution {
public:
    // TC : O(M * log(N)) Where M = fruits.size(), N = baskets.size()
    // SC : O(N)
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int m = fruits.size(), n = baskets.size();

        SGT st(n);
        st.buildSegTree(0, 0, n - 1, baskets);

        int cntUnplaced = 0;
        for (int i = 0; i < m; i ++) {
            if (st.search(fruits[i], 0, 0, n - 1) == -1) {
                cntUnplaced += 1;
            }
        }
        return cntUnplaced;
    }
};