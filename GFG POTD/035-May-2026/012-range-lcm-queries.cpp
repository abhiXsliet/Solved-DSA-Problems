// https://www.geeksforgeeks.org/problems/range-lcm-queries3348/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    long long getLCM(long long a, long long b) {
        return (a * b) / __gcd(a, b);
    }

    class SegmentTree {
    public:
        int n;
        vector<long long> seg;

        SegmentTree(vector<int>& arr) {
            n = arr.size();
            seg.resize(4 * n);

            build(arr, 0, 0, n - 1);
        }

        void build(vector<int>& arr, int i, int l, int r) {
            if (l == r) {
                seg[i] = arr[l];
                return;
            }

            int mid = l + (r - l) / 2;

            build(arr, 2 * i + 1, l, mid);
            build(arr, 2 * i + 2, mid + 1, r);

            seg[i] = (seg[2 * i + 1] * seg[2 * i + 2]) /
                     __gcd(seg[2 * i + 1], seg[2 * i + 2]);
        }

        void updateQuery(int idx, int val, int i, int l, int r) {
            if (l == r) {
                seg[i] = val;
                return;
            }

            int mid = l + (r - l) / 2;

            if (idx <= mid)
                updateQuery(idx, val, 2 * i + 1, l, mid);
            else
                updateQuery(idx, val, 2 * i + 2, mid + 1, r);

            seg[i] = (seg[2 * i + 1] * seg[2 * i + 2]) /
                     __gcd(seg[2 * i + 1], seg[2 * i + 2]);
        }

        long long rangeLCM(int start, int end,
                           int i, int l, int r) {

            // completely outside
            if (r < start || l > end)
                return 1;

            // completely inside
            if (l >= start && r <= end)
                return seg[i];

            int mid = l + (r - l) / 2;

            long long left =
                rangeLCM(start, end, 2 * i + 1, l, mid);

            long long right =
                rangeLCM(start, end, 2 * i + 2, mid + 1, r);

            return (left * right) / __gcd(left, right);
        }

        void update(int idx, int val) {
            updateQuery(idx, val, 0, 0, n - 1);
        }

        long long query(int l, int r) {
            return rangeLCM(l, r, 0, 0, n - 1);
        }
    };
    
    // TC : O(Q * log(N) * log(N))
    // SC : O(N)
    vector<long long> RangeLCMQuery(vector<int> &arr,
                                    vector<vector<int>> &queries) {

        SegmentTree st(arr);

        vector<long long> ans;

        for (auto &q : queries) {

            // update query
            if (q[0] == 1) {
                int idx = q[1];
                int val = q[2];

                st.update(idx, val);
            }

            // range query
            else {
                int l = q[1];
                int r = q[2];

                ans.push_back(st.query(l, r));
            }
        }

        return ans;
    }
};