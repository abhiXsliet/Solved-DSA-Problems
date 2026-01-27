// https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, int> P;

    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<P>> adj;
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({w, v});
            adj[v].push_back({2*w, u}); // reveresed edge
        }

        vector<int> result(n, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        result[0] = 0;

        while (!pq.empty()) {
            int dist  = pq.top().first;
            int fNode = pq.top().second;
            pq.pop();

            if (fNode == n - 1) return result[n - 1];

            for (auto &nbr : adj[fNode]) {
                int adjDist = nbr.first;
                int adjNode = nbr.second;

                if (dist + adjDist < result[adjNode]) {
                    result[adjNode] = dist + adjDist;
                    pq.push({result[adjNode], adjNode});
                }
            } 
        }

        return -1;
    }
};