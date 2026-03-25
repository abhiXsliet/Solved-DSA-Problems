// https://www.geeksforgeeks.org/problems/minimum-height-roots/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        if (V == 1) return {0};

        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;

        // push all leaves
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        int remainingNodes = V;

        while (remainingNodes > 2) {
            int sz = q.size();
            remainingNodes -= sz;

            while (sz--) {
                int node = q.front(); q.pop();

                for (int nei : adj[node]) {
                    degree[nei]--;
                    if (degree[nei] == 1) {
                        q.push(nei);
                    }
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};