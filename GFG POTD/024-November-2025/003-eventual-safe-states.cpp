// https://www.geeksforgeeks.org/problems/eventual-safe-states/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Step 1️⃣: Build adjacency list properly from edge list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        // Step 2️⃣: Create reverse graph and compute indegree
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V, 0);
        
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                adjRev[it].push_back(i); // reverse edge i->it to it->i
                indegree[i]++;           // increment indegree of original node
            }
        }
        
        // Step 3️⃣: Push all nodes with indegree = 0 into queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        // Step 4️⃣: Standard Kahn’s BFS
        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for (auto it : adjRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        
        // Step 5️⃣: Sort safe nodes
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};