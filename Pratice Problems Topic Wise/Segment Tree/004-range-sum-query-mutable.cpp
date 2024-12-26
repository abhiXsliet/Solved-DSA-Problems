// https://leetcode.com/problems/range-sum-query-mutable/



#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    int n;
    vector<int> seg;
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg = vector<int> (4*n, 0);
        buildSegmentTree(nums, 0, 0, n - 1);
    }

    // TC : O(N)
    // SC : O(N)
    void buildSegmentTree(vector<int>& nums, int i, int l, int r) {
        if (l == r) {
            seg[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegmentTree(nums, 2*i+1, l, mid);
        buildSegmentTree(nums, 2*i+2, mid+1, r);

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    // TC : O(log(N))
    // SC : O(1)
    void updateQuery(int updateIdx, int i, int l, int r, int val) {
        if (l == r) {
            seg[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if (updateIdx <= mid)
            updateQuery(updateIdx, 2*i+1, l, mid, val);
        else 
            updateQuery(updateIdx, 2*i+2, mid+1, r, val);

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    
    // TC : O(log(N))
    // SC : O(1)
    int getSummationInRange(int start, int end, int i, int l, int r) {
        if (r < start || l > end || l > r) // out of bound
            return 0;

        if (l >= start && r <= end)     // in-bound
            return seg[i];

        int mid  = l + (r - l) / 2;
        int lVal = getSummationInRange(start, end, 2*i+1, l, mid);
        int rVal = getSummationInRange(start, end, 2*i+2, mid+1, r);

        return lVal + rVal;
    }

    // TC : O(log(N)) -> point update
    // SC : O(1)
    void update(int index, int val) {
        updateQuery(index, 0, 0, n - 1, val);
    }
    
    // TC : O(log(N))
    // SC : O(1)
    int sumRange(int left, int right) {
        return getSummationInRange(left, right, 0, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */