// https://www.geeksforgeeks.org/problems/shortest-path-using-atmost-one-curved-edge--170647/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        int E = edges.size();
        vector<vector<vector<int>>> adj(V);
        for(int i = 0; i < E; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2], edges[i][3]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2], edges[i][3]});
        } 
        vector<vector<int>> dist(V, vector<int>(2, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, a}); pq.push({0, 1, a});
        dist[a][0] = 0; dist[a][1] = 0;
        while(!pq.empty()) {
            auto it1 = pq.top();
            pq.pop();
            int d = it1[0], i = it1[1], n = it1[2];
            if(d > dist[n][i]) continue;
            dist[n][i] = d;
            for(auto it2 : adj[n]) {
                int nbr = it2[0], d1 = it2[1], d2 = it2[2];
                if(dist[nbr][i] > d + d1) {
                    pq.push({d + d1, i, nbr});
                    dist[nbr][i] = d + d1;
                }
                if(i == 1) continue;
                if(dist[nbr][1] > d + d2) {
                    pq.push({d + d2, 1, nbr});
                    dist[nbr][1] = d + d2;
                }
            }
        }
        int ans = min(dist[b][0], dist[b][1]);
        if(ans == INT_MAX) ans = -1;
        return ans;
    }
};