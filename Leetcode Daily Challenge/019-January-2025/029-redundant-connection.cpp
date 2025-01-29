// https://leetcode.com/problems/redundant-connection/



#include <bits/stdc++.h>
using namespace std;

class DSU {
    public:
    int size;
    vector<int> rank;
    vector<int> parent;
    
    DSU(int n) {
        size = n + 1;
        rank.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i ++) {
            rank[i]   = 0;
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = findParent(parent[u]);   // path compression
    }

    void doUnion(int u, int v) {
        int u_parent = findParent(u);
        int v_parent = findParent(v);
        
        if (u_parent == v_parent) {
            return;
        }

        if (rank[u_parent] > rank[v_parent]) {
            parent[v_parent] = u_parent;
        } else if (rank[u_parent] < rank[v_parent]) {
            parent[u_parent] = v_parent;
        } else {
            parent[v_parent] = u_parent;
            rank[u_parent]  += 1;
        }
    }
};

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    bool bfs (unordered_map<int, vector<int>>& adj, int u, int v, vector<bool>& vis) {
        queue<int> q;
        vis[u] = true;
        q.push(u);
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == v) return true;

            for (int& nbr : adj[node]) {
                if (!vis[nbr]) {
                    q.push(nbr);
                    vis[nbr] = 1;
                }
            }
        }
        return {};
    }

    // TC : O(N)
    // SC : O(N) Recursive call stack space
    bool dfs(unordered_map<int, vector<int>>& adj, int u, int v, vector<bool>& vis) {
        vis[u] = true;
        if (u == v) return true;
        for (auto& nbr : adj[u]) {
            if (!vis[nbr] && dfs(adj, nbr, v, vis)) {
                return true;
            }
        }
        return false;
    }

    // TC : O(N^2)
    // SC : O(N)
    vector<int> approach_1(vector<vector<int>>& edges) {
        int n = edges.size();

        unordered_map<int, vector<int>> adj;
        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            vector<bool> visited(n, false);
            if (adj.count(u) && adj.count(v) && dfs(adj, u, v, visited)) {
                return edge;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }

    // TC : O(N^2)
    // SC : O(N)
    vector<int> approach_2(vector<vector<int>>& edges) {
        int n = edges.size();

        unordered_map<int, vector<int>> adj;
        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            vector<bool> visited(n, false);
            if (adj.count(u) && adj.count(v) && bfs(adj, u, v, visited)) {
                return edge;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }

    // TC : O(N * alpha(N))
    // SC : O(N)
    vector<int> approach_3(vector<vector<int>>& edges) {
        int n = edges.size();

        DSU dsu(n); // O(alpha(N))

        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            if (dsu.findParent(u) == dsu.findParent(v)) {
                return edge;
            }
            dsu.doUnion(u, v);
        }
        return {};
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // return approach_1(edges);    // DFS  
        // return approach_2(edges);    // BFS
        return approach_3(edges);    // DSU
    }
};