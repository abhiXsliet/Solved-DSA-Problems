// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<int, int> P;

    // TC : O(E * log(V))
    // SC : O(N)
    int dijkstras(int n, unordered_map<int, vector<P>>& adj) {
        vector<int> dist(n, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        dist[0] = 0;

        while(!pq.empty()) {
            int d    = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == n- 1) {
                return dist[n - 1];
            }

            for (auto& nbr : adj[node]) {
                int adjNode = nbr.first;
                int wt      = nbr.second;

                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    pq.push({d + wt, adjNode});
                }
            }
        }
        return dist[n - 1];
    }

    // TC : O(V + E) Where V = No. of Vertices and E = No. of Edges
    // SC : O(V)
    int bfs(int n, unordered_map<int, vector<int>>& adj) {
        queue<int> q;
        vector<int> vis(n, 0);
        vis[0] = 1;
        q.push(0);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size --) {
                int fNode = q.front();
                q.pop();

                if (fNode == n - 1) {
                    return level;
                }

                for (auto& nbr : adj[fNode]) {
                    if (!vis[nbr]) {
                        vis[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }
            level ++;
        }
        return -1;
    }

    // TC : O(q * (V + E))
    // SC : O(V + E)
    vector<int> approach_1(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i <= n - 2; i ++) {
            adj[i].push_back(i + 1);
        }

        vector<int> result;
        for (auto& q : queries) {
            adj[q[0]].push_back(q[1]);
            result.push_back(bfs(n, adj));
        }
        return result;
    }

    // TC : O(q * E * log(V))
    // SC : O(V + E)
    vector<int> approach_2(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<P>> adj;
        for (int i = 0; i <= n - 2; i ++) {
            adj[i].push_back({i + 1, 1});
        }

        vector<int> result;
        for (auto& q : queries) {
            adj[q[0]].push_back({q[1], 1});
            result.push_back(dijkstras(n, adj));
        }
        return result;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // return approach_1(n, queries);   // BFS

        return approach_2(n, queries);   // Dijkstras
    }
};