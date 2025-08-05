// https://leetcode.com/problems/fruits-into-baskets-ii/

// similar only contraint high : https://leetcode.com/problems/fruits-into-baskets-iii/


#include <bits/stdc++.h>
using namespace std;

class SGT {
public:
    vector<int> segTree;
    SGT(int n) {
        segTree.resize(4*n, 0);
    }

    void build(int i, int l, int r, vector<int> &arr) {
        if (l == r) {
            segTree[i] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * i + 1, l, mid, arr);
        build(2 * i + 2, mid + 1, r, arr);

        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    bool query(int tar, int i, int l, int r) {
        if (segTree[i] < tar)
            return false;

        if (l == r) {
            segTree[i] = -1;    // value gets used so mark it as minimum
            return true;
        }

        int mid = l + (r - l) / 2;

        bool found = (segTree[2 * i + 1] >= tar) ? query(tar, 2 * i + 1, l, mid) : query(tar, 2 * i + 2, mid + 1, r);

        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);

        return found;
    }
};

class Solution {
public:
    // TC : O(N * log(M))
    // SC : O(M)
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), m = baskets.size();

        SGT sgt(m);
        sgt.build(0, 0, m - 1, baskets);

        int cntUnplaced = 0;
        for (int &fruit : fruits) {
            if (!sgt.query(fruit, 0, 0, m - 1)) {
                cntUnplaced += 1;
            }
        }
        return cntUnplaced;
    }
};