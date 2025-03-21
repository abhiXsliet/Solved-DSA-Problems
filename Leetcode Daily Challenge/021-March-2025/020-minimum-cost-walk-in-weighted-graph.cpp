// https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> parent;

    int findParent(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = findParent(parent[x]);
    }

    void Union(int x, int y) {
        parent[y] = x;
    }
public:
    // TC : O(E + Qα(n)), where E is the number of edges, Q is the number of queries, and α(n) is the inverse Ackermann function.
    // SC : O(N)
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        vector<int> cost(n, -1);

        for (int i = 0; i < n; i ++) {
            parent[i] = i;
        }

        for (vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            int parent_u = findParent(u);
            int parent_v = findParent(v);

            if (parent_u != parent_v) {
                Union(parent_u, parent_v);
                cost[parent_u] &= cost[parent_v];
            } 
            cost[parent_u] &= w;
        }

        vector<int> result;
        for (vector<int> &q : query) {
            int s = q[0];
            int e = q[1];

            int parent_s = findParent(s);
            int parent_e = findParent(e);

            if (s == e) {
                result.push_back(0);
            } else if (parent_s != parent_e) {
                result.push_back(-1);
            } else {
                result.push_back(cost[parent_s]);
            }
        }
        return result;
    }
};