// https://leetcode.com/problems/critical-connections-in-a-network/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(V + E)
    // SC : O(V) -> Recursive Depth
    void DFS(int node, int parent, int timer, unordered_map<int, bool>& vis, 
             unordered_map<int, vector<int>>& adj ,vector<int>& disc, 
             vector<int>& low, vector<vector<int>>& result) {
        
        vis[node] = 1;
        disc[node] = low[node] = timer ++;

        for (auto& neigh : adj[node]) {
            if (neigh == parent) continue;
            
            else if (!vis[neigh]) {
                DFS(neigh, node, timer, vis, adj, disc, low, result);
                // While returning make sure to update the low[node]
                low[node] = min(low[node], low[neigh]);

                // Check Bridge -> Bridge Condn. 
                if (low[neigh] > disc[node]) {
                    result.push_back({node, neigh});
                }
            }
            else {
                // Back Edge => neigh != parent && vis[neigh] = 1;
                low[node] = min(low[node], disc[neigh]);
            }
        }
    }
public:
    // TC : O(V + E) Where E = No. Of Edges
    // SC : O(V)     Where V = No. Of Vertices
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Prepare Adjacenty List
        unordered_map<int, vector<int>> adj;
        for(auto& connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        // Initialize all data structures
        vector<int> discovery(n, -1);
        vector<int> low(n, -1);
        unordered_map<int, bool> visited(n);

        int parent = -1;
        int timer  =  0;

        vector<vector<int>> result;

        // Traverse On All Connected Components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(i, parent, timer, visited, adj, discovery, low, result);
            }
        }

        return result;
    }
};