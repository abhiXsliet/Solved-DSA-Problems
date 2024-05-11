// https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/description/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<int, int> P;

    void dijkstras(unordered_map<int, vector<P>>& adj, vector<int>& disappear, vector<int>& dist, int src) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({src, 0});
        dist[src] = 0;

        while(!pq.empty()) {
            int fNode  = pq.top().first;
            int prev_d = pq.top().second;
            pq.pop();

            // If the current shortest distance doesn't match the one in the priority queue, skip the processing
            if (prev_d != dist[fNode]) continue;

            // reaching to the node's after it became disappeared
            if (prev_d >= disappear[fNode]) continue;
            
            for (auto& nbr : adj[fNode]) {

                int new_dist = prev_d + nbr.second;
                
                if (new_dist < dist[nbr.first]) {

                    pq.push({nbr.first, new_dist});
                    dist[nbr.first] = new_dist;
                }
            }
        }
    }

    void Dijkstra(unordered_map<int, vector<P>>& adj, vector<int>& disappear,
                 vector<int>& dist, vector<int>& visi, int src) {
        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0, src});

        while(!q.empty()) {
            int fNode  = q.top().second;
            int prev_d = q.top().first;
            q.pop();

            // if node is already visted or node's reaching dist >= node's disappear val then continue
            if (visi[fNode] || prev_d >= disappear[fNode]) continue;

            dist[fNode] = prev_d;
            visi[fNode] = 1;
            
            for (auto& nbr : adj[fNode]) {
                if (!visi[nbr.first]) {
                    q.push({nbr.second + prev_d, nbr.first});
                }
            }
        }
    }

    // TC : O(V + E * log(V))
    // SC : O(V + E)
    vector<int> way_1(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        unordered_map<int, vector<P>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dist(n, -1), vis(n, 0);
        Dijkstra(adj, disappear, dist, vis, 0);

        return dist;
    }

    // TC : O(V + E * log(V))
    // SC : O(V + E)
    vector<int> way_2(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        unordered_map<int, vector<P>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dist(n, INT_MAX);
        dijkstras(adj, disappear, dist, 0);

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dist[i] < disappear[i]) {
                ans.push_back(dist[i]);
            }
            else ans.push_back(-1);
        }

        return ans;
    }
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        // return way_1(n, edges, disappear);

        return way_2(n, edges, disappear);
    }
};