// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/



#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    int components;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        components = n;

        for (int i = 1; i <= n; i ++) {
            parent[i] = i;
        }
    }

    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }

        return parent[x] = findParent(parent[x]);
    }

    void unionSet (int x, int y) {
        int x_parent = findParent(x);
        int y_parent = findParent(y);

        if (x_parent > y_parent) {
            parent[y_parent] = x;
        
        } else if (x_parent < y_parent) {
            parent[x_parent] = y;
        
        } else {    // parent_x == parent_y
            parent[x_parent] = y_parent;
            rank[x_parent]  += 1;
        }

        components --;  // Track the components to ensure that, in the end, 
                        // Alice and Bob have an equal number of components remaining.
    }

    bool isSingleComponent() {
        return components == 1;
    }
};

class Solution {
public:
    // TC : O(M * log(M))  where M is the total number of edges
    //      + O(M * α(N)), Where α is the inverse Ackermann function.
    //      Union-find operations take O(α(N)) time. Looping over all edges takes O(M) time, with each find and union operation inside the loop taking O(α(N)) time.
    // SC: O(N)
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n);
        DSU Bob(n);

        auto cmp = [&](vector<int> a, vector<int> b) {
            return a[0] > b[0];
        };
        // Sort the edges so that the common edge processed first : both alice and bob can traverse
        sort(begin(edges), end(edges), cmp);

        int edgeCount = 0;

        // Processing each edges
        for (vector<int>& edge : edges) {
            int type = edge[0];
            int x    = edge[1];
            int y    = edge[2];

            if (type == 3) {    // both alice and bob can traverse, so do union for both
                bool isEdgeAdded = false;

                if (Alice.findParent(x) != Alice.findParent(y)) {
                    Alice.unionSet(x, y);
                    isEdgeAdded = true;
                }

                if (Bob.findParent(x) != Bob.findParent(y)) {
                    Bob.unionSet(x, y);
                    isEdgeAdded = true;
                }

                if (isEdgeAdded) edgeCount ++;
                
            } else if (type == 1) {
                if (Alice.findParent(x) != Alice.findParent(y)) {
                    Alice.unionSet(x, y);
                    edgeCount ++;
                }
            } else {
                if (Bob.findParent(x) != Bob.findParent(y)) {
                    Bob.unionSet(x, y);
                    edgeCount ++;
                }
            }
        }

        // Check if in the end, both alice and bob have the same components == 1
        if (Alice.isSingleComponent() && Bob.isSingleComponent()) {
            return edges.size() - edgeCount;
        }

        return -1;
    }
};