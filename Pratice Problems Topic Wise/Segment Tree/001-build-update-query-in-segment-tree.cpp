#include <bits/stdc++.h>   
using namespace std;
int arr[100005], seg[4*100005]; // segment tree is of the 4*times the size of array

// TC : O(2*N) ~= O(N) Traversing each node 2-times 
// SC : O(4*N) ~= O(N)
void buildSegmentTree(int i, int left, int right) {
    // base case
    if (left == right) {
        seg[i] = arr[left]; // seg[idx] = arr[right];
        return;
    }
    
    int mid = (left + right) >> 1;

    buildSegmentTree(2*i + 1, left, mid);
    buildSegmentTree(2*i + 2, mid + 1, right);

    seg[i] = seg[2*i + 1] + seg[2*i + 2];
}

// TC : O(log(N))
void updateSegmentTree(int idx, int val, int i, int l, int r) {
    if (l == r) {
        seg[i] = val;
        return;
    }

    int mid = (l + r) >> 1;

    if (idx <= mid) // go to left 
        updateSegmentTree(idx, val, 2*i + 1, l, mid);
    else  // go to right
        updateSegmentTree(idx, val, 2*i + 2, mid + 1, r);

    seg[i] = seg[2*i + 1] + seg[2*i + 2];
}

// TC : O(log(N))
// start : starting of the query
// end   : ending of the query
int queryUpdate(int start, int end, int i, int l, int r) {
    int mid = (l + r) >> 1;
    if (l > end || r < start) { // out of bound
        return 0;
    }
    if (l >= start && r <= end) {   // complete overlapping
        return seg[i];
    }
    // else partially overlapping
    return (queryUpdate(start, end, 2*i + 1, l, mid) + queryUpdate(start, end, 2*i + 2, mid + 1, r));
}

int main() {
    int n;
    cout << "Size of array  : ";
    cin >> n;
    cout << "Enter Elements : ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Building A Segment Tree
    buildSegmentTree(0, 0, n - 1);

    for (int i = 0; i < 4*n; i++) {
        cout << seg[i] << " ";
    }
    cout << endl;

    int idx, val;
    cout << "\nEnter index and val to update (space separated): ";
    cin >> idx >> val;

    // Updating Segment Tree at given index with a new value
    updateSegmentTree(idx, val, 0, 0, n - 1);

    for (int i = 0; i < 4*n; i++) {
        cout << seg[i] << " ";
    }
    cout << endl;

    // Query Updation 
    int q;
    cout << "\nEnter total no. of queries: ";
    cin >> q;

    while (q--) {
        int start, end;
        cout << "Enter start of query: ";
        cin >> start;
        cout << "Enter end of query  : ";
        cin >> end;
        queryUpdate(start, end, 0, 0, n - 1);
        for (int i = 0; i < 4*n; i++) {
            cout << seg[i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}