// https://leetcode.com/problems/find-if-path-exists-in-graph/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N) -> Queue
    bool bfs(unordered_map<int, vector<int>>& adj, int src, int dest, vector<bool>& vis) {
        queue<int> q;
        q.push(src);
        vis[src] = 1; 

        while(!q.empty()) {
            int fNode = q.front();
            q.pop();
            
            if (fNode == dest) return 1;

            for (auto& nbr : adj[fNode]) {
                if (!vis[nbr]) {
                    q.push(nbr);
                    vis[nbr] = 1;
                }
            }
        }
        return 0;
    }

    // TC : O(N)
    // SC : O(N) -> Recursive Depth
    bool dfs(unordered_map<int, vector<int>>& adj, int src, int dest, vector<bool>& vis) {
        if (src == dest) return 1;
        if (vis[src]) return 0;

        vis[src] = 1; 

        for (auto& nbr : adj[src]) {
            if (dfs(adj, nbr, dest, vis)) {
                return 1;
            }
        }
        return 0;
    }
    
    // TC : O(N)
    // SC : O(N) -> Recursive Depth
    bool approach_1(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, 0);
        return dfs(adj, source, destination, visited);
    }

    // TC : O(N)
    // SC : O(N) -> Queue
    bool approach_2(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, 0);
        return bfs(adj, source, destination, visited);
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // return approach_1(n, edges, source, destination);

        return approach_2(n, edges, source, destination);
    }
};