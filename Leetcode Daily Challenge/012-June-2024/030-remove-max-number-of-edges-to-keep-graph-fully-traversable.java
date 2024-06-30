// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/



import java.util.*;

class DSU {
    public int[] parent;
    public int[] rank;
    public int components;

    DSU(int n) {
        parent = new int[n + 1];
        rank   = new int[n + 1];
        components = n;

        for (int i = 1; i <= n; i ++) {
            parent[i] = i;
        }
    }

    public int findParent(int x) {
        if (x == parent[x]) 
            return x;
        
        return parent[x] = findParent(parent[x]);
    }

    public void unionSet(int x, int y) {
        int xParent = findParent(x);
        int yParent = findParent(y);

        if (xParent > yParent) {
            parent[yParent] = x;

        } else if (xParent < yParent) {
            parent[xParent] = y;

        } else {
            parent[yParent] = x;
            rank[xParent] ++;
        }

        components --; // Track the components to ensure that, in the end,
                       // Alice and Bob have an equal number of components remaining.
    }

    public boolean isSingleComponent() {
        return components == 1;
    }
}

class Solution {
    // Time Complexity: O(M * log(M)) where M is the total number of edges
    //   + O(M * α(N)), where α is the inverse Ackermann function.
    //   Union-find operations take O(α(N)) time. Looping over all edges takes O(M) time, with each find and union operation inside the loop taking O(α(N)) time.
    
    // Space Complexity: O(N)
    public int maxNumEdgesToRemove(int n, int[][] edges) {
        DSU Alice = new DSU(n);
        DSU Bob   = new DSU(n);

        // sort the edges based on the type-3
        Arrays.sort(edges, (a, b) -> b[0] - a[0]);

        int edgesCount = 0;

        for (int[] edge : edges) {
            int type = edge[0];
            int x    = edge[1];
            int y    = edge[2];

            if (type == 3) {    // both alice and bob can traverse
                boolean isEdgesAdded = false;
                if (Alice.findParent(x) != Alice.findParent(y)) {
                    Alice.unionSet(x, y);
                    isEdgesAdded = true;
                }
                if (Bob.findParent(x) != Bob.findParent(y)) {
                    Bob.unionSet(x, y);
                    isEdgesAdded = true;
                }
                if (isEdgesAdded) edgesCount ++;
            } else if (type == 2) { // only Bob can traverse on the edge type = 2
                if (Bob.findParent(x) != Bob.findParent(y)) {
                    Bob.unionSet(x, y);
                    edgesCount ++;
                }
            } else {    // only Alice is allowed to traverse on edge type = 1
                if (Alice.findParent(x) != Alice.findParent(y)) {
                    Alice.unionSet(x, y);
                    edgesCount ++;
                }
            }
        }

        if (Alice.isSingleComponent() && Bob.isSingleComponent()) {
            return edges.length - edgesCount;
        }

        return -1;
    }
}