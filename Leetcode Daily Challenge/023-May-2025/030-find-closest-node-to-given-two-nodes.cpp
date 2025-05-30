// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(vector<int> &edges, int src, vector<int> &dist, vector<bool>& visited) {
        queue<pair<int, int>> q;
        q.push({src, 0});
        visited[src] = 1;
        while (!q.empty()) {
            int u = q.front().first;
            int d = q.front().second;
            q.pop();

            int v = edges[u];

            if (v != -1 && !visited[v]) {
                visited[v] = 1;
                dist[v] = 1 + d;
                q.push({v, dist[v]});
            }
        }
    }

    void dfs(vector<int> &edges, int u, vector<int> &dist, vector<bool>& visited) {
        visited[u] = 1;

        int v = edges[u];

        if (v != -1 && !visited[v]) {
            visited[v] = 1;
            dist[v] = 1 + dist[u];
            dfs(edges, v, dist, visited);
        }
    }
public:
    // TC : O(2*(V + E)) ~= O(N)
    // SC : O(N)
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
        vector<bool> visited1(n, 0), visited2(n, 0);
        
        dist1[node1] = dist2[node2] = 0;

        // dfs(edges, node1, dist1, visited1);
        // dfs(edges, node2, dist2, visited2);

        bfs(edges, node1, dist1, visited1);
        bfs(edges, node2, dist2, visited2);

        int minDistance = INT_MAX;
        int minDistNode = -1;

        for (int i = 0; i < n; i ++) {
            int dist = max(dist1[i], dist2[i]);
            if (minDistance > dist) {
                minDistance = dist;
                minDistNode = i;
            }
        }

        return minDistNode;
    }
};