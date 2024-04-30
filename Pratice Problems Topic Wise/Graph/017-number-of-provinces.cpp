// https://leetcode.com/problems/number-of-provinces/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(unordered_map<int, vector<int>>& adj, vector<bool>& vis, int src) {
        vis[src] = 1;
        for (auto& nbr : adj[src]) {
            if (!vis[nbr]) {
                vis[nbr] = 1;
                dfs(adj, vis, nbr);
            }
        }
    }

    void DFS(vector<vector<int>>& isConnected, vector<bool>& vis, int u, int n) {
        vis[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && isConnected[u][v]) {
                vis[v] = 1;
                DFS(isConnected, vis, v, n);
            }
        }
    }

    void BFS(vector<vector<int>>& isConnected, vector<bool>& vis, int u, int n) {
        queue<int> q;
        q.push(u);
        vis[u] = 1;
        while(!q.empty()) {
            int fNode = q.front();
            q.pop();
            for (int v = 0; v < n; v ++) {
                if (!vis[v] && isConnected[fNode][v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    // TC : O(V + E)
    // SC : O(V) Where V = No. of Nodes
    int solve_1(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, vector<int>> adj;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n, 0);
        int cntProvinces = 0;
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(adj, vis, i);
                cntProvinces += 1;
            }
        }

        return cntProvinces;
    }

    // TC : O(V + E)
    // SC : O(V) Where V = No. of Nodes
    int solve_2(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, 0);
        int cntProvinces = 0;
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                DFS(isConnected, vis, i, n);
                cntProvinces += 1;
            }
        }

        return cntProvinces;
    }

    // TC : O(V + E)
    // SC : O(V) Where V = No. of Nodes
    int solve_3(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, 0);
        int cntProvinces = 0;
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                BFS(isConnected, vis, i, n);
                cntProvinces += 1;
            }
        }

        return cntProvinces;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // return solve_1(isConnected);     // ADJACENCY LIST CREATED : dfs

        // return solve_2(isConnected);     // WITHOUT ADJACENCY LIST : DFS

        return solve_3(isConnected);        // Using BFS
    }
};