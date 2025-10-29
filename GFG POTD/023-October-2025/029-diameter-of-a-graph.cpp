// https://www.geeksforgeeks.org/problems/diameter-of-a-graph/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // Helper BFS that returns {farthestNode, distance}
    pair<int, int> bfs(int start, vector<vector<int>>& adj, int V) {
        vector<int> dist(V, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        
        int farNode = start;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            farNode = node;
            
            for (int nei : adj[node]) {
                if (dist[nei] == -1) {
                    dist[nei] = dist[node] + 1;
                    q.push(nei);
                }
            }
        }
        return {farNode, dist[farNode]};
    }
    
  public:
    int diameter(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        // Step 1: BFS from any node (say 0)
        auto first = bfs(0, adj, V);
        
        // Step 2: BFS from farthest node found in step 1
        auto second = bfs(first.first, adj, V);
        
        // Step 3: Distance between them is the diameter
        return second.second;
    }
};