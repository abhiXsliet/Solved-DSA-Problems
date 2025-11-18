// https://www.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        const long long INF = LLONG_MAX / 4;
        const int MOD = 1'000'000'007;

        // build adjacency list for undirected graph
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        // dist[] and ways[]
        vector<long long> dist(V, INF);
        vector<long long> ways(V, 0);

        // Dijkstra min-heap (dist, node)
        using pll = pair<long long,int>;
        priority_queue<pll, vector<pll>, greater<pll>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue; // stale entry

            for (auto &pr : adj[u]) {
                int v = pr.first;
                long long w = pr.second;
                long long nd = d + w;

                if (nd < dist[v]) {
                    // found strictly shorter path
                    dist[v] = nd;
                    ways[v] = ways[u];
                    pq.push({nd, v});
                } else if (nd == dist[v]) {
                    // found another shortest path
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return (int)(ways[V-1] % MOD);
    }
};