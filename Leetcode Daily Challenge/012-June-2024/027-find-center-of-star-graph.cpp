// https://leetcode.com/problems/find-center-of-star-graph/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(V + E) Where V = No. of Nodes & E = Edges b/w Nodes
    // SC : O(V + E)
    int approach_1(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (auto& it : adj) {
            if(it.second.size() == edges.size()) {
                return it.first;
            }
        }

        return -1;  // not possible 
    }

    int approach_2(vector<vector<int>>& edges) {
        int n = edges.size() + 1;    // Nodes : 1 to (n + 1)

        vector<int> inDegree(n+1, 0);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            inDegree[u] ++;
            inDegree[v] ++;
        }

        for (int i = 1; i <= n; i ++) {
            if (inDegree[i] == (n - 1))   // edges : (n - 1)
                return i;
        }

        return -1;  // not possible 
    }

    // TC : O(1)
    // SC : O(1)
    int approach_3(vector<vector<int>>& edges) {
        int n = edges.size() + 1; // Nodes 1 to (n + 1)

        vector<int> firstEdge  = edges[0];
        vector<int> secondEdge = edges[1];

        int centerNode = 0;
        
        if (firstEdge[0] == secondEdge[0] || firstEdge[0] == secondEdge[1]) {
            centerNode = firstEdge[0];
        } else if (firstEdge[1] == secondEdge[0] || firstEdge[1] == secondEdge[1]) {
            centerNode = firstEdge[1];
        }

        return centerNode;
    }
public:
    int findCenter(vector<vector<int>>& edges) {
        // return approach_1(edges);    // Using : Adjacency List

        // return approach_2(edges);    // Using : Indegree of Nodes

        return approach_3(edges);       // Pick 2-edges, check which element is present in both
    }
};