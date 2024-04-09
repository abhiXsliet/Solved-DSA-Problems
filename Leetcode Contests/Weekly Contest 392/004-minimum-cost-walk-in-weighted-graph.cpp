// https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/



#include <bits/stdc++.h>
using namespace std;

// T.C : 
/*
    The time complexity of the union-find operations (with path compression) is approximately O(α(n)), 
    where α is the inverse Ackermann function, which is practically constant for all reasonable values of n.
    The time complexity of processing each edge and each query is O(1).
    Therefore, the overall time complexity of the algorithm is O(E + Qα(n)), where E is the number of edges, 
    Q is the number of queries, and α(n) is the inverse Ackermann function.
*/
// S.C : O(n)
class Solution {
private:    
    vector<int> parent;
    int findParent(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = findParent(parent[x]);
    }

    int Union(int x, int y) {
        return parent[y] = x;
    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            // Initially everyone is a parent of themselves
            parent[i] = i;  
        }
        // Initially everyone has a cost of -1
        vector<int> cost(n, -1);

        for (auto& edge : edges) {
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
        for (auto& q : query) {
            int s = q[0];
            int t = q[1];

            int parent_s = findParent(s);
            int parent_t = findParent(t);

            if (s == t) {
                result.push_back(0);
            }
            else if (parent_s != parent_t) {  // belongs to the different components
                result.push_back(-1);
            }
            else {  // belongs to the same component
                result.push_back(cost[parent_s]);
            }
        }
        return result;
    }
};