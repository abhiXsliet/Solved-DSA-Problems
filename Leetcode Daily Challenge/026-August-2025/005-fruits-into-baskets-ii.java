// https://leetcode.com/problems/fruits-into-baskets-ii/

// similar (constraint high) : https://leetcode.com/problems/fruits-into-baskets-iii/

class SGT {
    int[] segTree;
    SGT(int n) {
        segTree = new int[4 * n];
    }

    public void build(int i, int l, int r, int[] fruits) {
        if (l == r) {
            segTree[i] = fruits[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * i + 1, l, mid, fruits);
        build(2 * i + 2, mid + 1, r, fruits);

        segTree[i] = Math.max(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    public boolean query(int tar, int i, int l, int r) {
        if (segTree[i] < tar) return false;

        if (l == r) {
            segTree[i] = -1;    // Mark as used
            return true;
        }

        int mid = l + (r - l) / 2;

        boolean found = (segTree[2 * i + 1] >= tar) ? query(tar, 2 * i + 1, l, mid) : query(tar, 2 * i + 2, mid + 1, r);

        segTree[i] = Math.max(segTree[2 * i + 1], segTree[2 * i + 2]);

        return found;
    }
}

class Solution {
    // TC : O(N * log(M))
    // SC : O(M)
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int n = fruits.length, m = baskets.length;

        SGT sgt = new SGT(m);
        sgt.build(0, 0, m - 1, baskets);

        int cntUnplaced = 0;
        for (int fruit : fruits) {
            if (!sgt.query(fruit, 0, 0, m - 1)) {
                cntUnplaced += 1;
            }
        }
        return cntUnplaced;
    }
}