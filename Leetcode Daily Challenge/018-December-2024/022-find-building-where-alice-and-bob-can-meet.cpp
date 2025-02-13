// https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int rangeMaxIndexQuery(int start, int end, int i, int l, int r, vector<int>& segTree, vector<int>& heights) {
        if (r < start || l > end) { // out of bound range
            return -1;
        }
        if (l >= start && r <= end) { // in-bound
            return segTree[i];
        }
        int mid = l + (r - l) / 2;
        int L = rangeMaxIndexQuery(start, end, 2*i+1, l,   mid, segTree, heights);
        int R = rangeMaxIndexQuery(start, end, 2*i+2, mid+1, r, segTree, heights);
        if (L == -1) return R;
        if (R == -1) return L;
        if (heights[L] >= heights[R]) return L;
        return R;
    }

    // This fn. builds the segment tree for the maximum index of the heights array
    void buildSegTree(vector<int>& heights, vector<int>& segTree, int i, int l, int r) {
        if (l == r) {
            segTree[i] = l;
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegTree(heights, segTree, 2*i+1, l, mid);
        buildSegTree(heights, segTree, 2*i+2, mid+1, r);
        
        int leftIdx  = segTree[2 * i + 1];
        int rightIdx = segTree[2 * i + 2];

        segTree[i] = (heights[leftIdx] >= heights[rightIdx]) ? leftIdx : rightIdx;
    }

    // Binary search helper to find the leftmost building higher than `height`
    int binarySearch(int height, vector<pair<int, int>>& st) {
        int l = 0, r = st.size() - 1, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (st[mid].first > height) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    int getCommonBuilding(int lQ, int rQ, vector<int>& heights) {
        int n = heights.size();
        if (lQ == rQ) return lQ;
        int ans = -1;
        for (int i = rQ; i < n; i ++) {
            if (heights[i] > heights[lQ] && heights[i] >= heights[rQ]) {
                return i;
            }
        }
        return ans;
    }

    // TC : O(Q * N)
    // SC : O(1)
    vector<int> approach_1(vector<int>& heights, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> result(q);
        for (int i = 0; i < q; i ++) {
            int lQ = queries[i][0];
            int rQ = queries[i][1];
            if (lQ > rQ) swap(lQ, rQ);
            result[i] = getCommonBuilding(lQ, rQ, heights);
        }
        return result;
    }

    // Optimized function to solve the problem
    vector<int> approach_2(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> answer(queries.size(), -1);
        vector<vector<pair<int, int>>> groupedQueries(n); // Queries grouped by Bob's position
        vector<pair<int, int>> st; // Monotonic stack for heights
        
        // Preprocess queries and initialize `answer` where possible
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0], b = queries[i][1];
            if (a > b) swap(a, b); // Ensure `a < b`
            
            // If Alice and Bob are already at the same building or Bob is taller
            if (a == b || heights[b] > heights[a]) {
                answer[i] = b;
            } else {
                // Otherwise, store the query for processing
                groupedQueries[b].emplace_back(heights[a], i);
            }
        }

        // Process the buildings in reverse order
        for (int i = n - 1; i >= 0; i--) {
            // Resolve queries for the current building `i`
            for (auto& [h, idx] : groupedQueries[i]) {
                int pos = binarySearch(h, st); // Find leftmost building taller than `h`
                if (pos != -1) answer[idx] = st[pos].second;
            }

            // Update the monotonic stack
            while (!st.empty() && st.back().first <= heights[i]) {
                st.pop_back();
            }
            st.emplace_back(heights[i], i);
        }

        return answer;
    }

    vector<int> approach_3(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), q = queries.size();

        vector<int> segTree(4*n);
        buildSegTree(heights, segTree, 0, 0, n - 1);

        vector<int> result;
        for (auto& query : queries) {
            int bob   = max(query[0], query[1]);
            int alice = min(query[0], query[1]);

            if (alice == bob || heights[bob] > heights[alice]) {
                result.push_back(bob);
                continue;
            }

            int s = bob + 1;
            int e = n - 1;
            int res = INT_MAX;
            while (s <= e) {
                int mid = s + (e - s) / 2;
                int idx = rangeMaxIndexQuery(s, mid, 0, 0, n - 1, segTree, heights);    // RMIQ

                if (heights[idx] > max(heights[alice], heights[bob])) {
                    res = min(res, idx);
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }

            if(res == INT_MAX) {
                result.push_back(-1);
            } else {
                result.push_back(res);
            }
        }
        return result;
    }
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        // return approach_1(heights, queries);    // BRUTE : TLE
        // return approach_2(heights, queries);   
        return approach_3(heights, queries);    // Segment Tree : Idle Soln.
    }
};