// https://leetcode.com/problems/count-the-number-of-complete-components/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void BFS(int src, int &cntEdges, int &cntVertices, vector<bool> &visited, unordered_map<int, vector<int>> &adj) {
        queue<int> q;
        q.push(src);
        visited[src] = 1;

        while (!q.empty()) {
            int fNode = q.front();
            q.pop();

            cntEdges    += adj[fNode].size();
            cntVertices += 1;

            for (int &nbr : adj[fNode]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = 1;
                }
            }
        }
    }

    void DFS(int src, int &cntEdges, int &cntVertices, vector<bool> &visited, unordered_map<int, vector<int>> &adj) {
        cntVertices += 1;
        visited[src] = 1;
        cntEdges += adj[src].size();
        for (int nbr : adj[src]) {
            if (!visited[nbr]) {
                DFS(nbr, cntEdges, cntVertices, visited, adj);
            }
        }
    }

    void prepareAdj(vector<vector<int>> &edges, unordered_map<int, vector<int>> &adj) {
        for (vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    }

    // TC : O(V + E)
    // SC : O(V + E) Where V = No. of Nodes
    int approach_1(int n, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        prepareAdj(edges, adj);

        vector<bool> visited(n, 0);

        int components = 0;

        // Traverse on all components
        for (int i = 0; i < n; i ++) {
            if (!visited[i]) {
                int cntEdges = 0;
                int cntVertices = 0;
                DFS(i, cntEdges, cntVertices, visited, adj);
                
                // required edges for a complete graph : nC2 => (n * (n - 1)) / 2
                int reqEdges = (cntVertices * (cntVertices - 1)) / 2;   
                
                if ((cntEdges / 2) == reqEdges) {
                    components += 1;
                }
            }
        }

        return components;
    }

    // TC : O(V + E)
    // SC : O(V + E) Where V = No. of Nodes
    int approach_2(int n, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        prepareAdj(edges, adj);

        vector<bool> visited(n, 0);

        int components = 0;

        // Traverse on all components
        for (int i = 0; i < n; i ++) {
            if (!visited[i]) {
                int cntEdges = 0;
                int cntVertices = 0;
                BFS(i, cntEdges, cntVertices, visited, adj);
                
                // required edges for a complete graph : nC2 => (n * (n - 1)) / 2
                int reqEdges = (cntVertices * (cntVertices - 1)) / 2;   
                
                if ((cntEdges / 2) == reqEdges) {
                    components += 1;
                }
            }
        }

        return components;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // return approach_1(n, edges);    // DFS  
        return approach_2(n, edges);    // BFS  
        // return approach_3(n, edges); // pending : DSU
    }
};