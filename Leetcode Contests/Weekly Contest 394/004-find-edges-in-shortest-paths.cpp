// https://leetcode.com/problems/find-edges-in-shortest-paths/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<int, int> P;
    typedef long long ll;

    // TC : O(V + E)
    // SC : O(V)
    vector<int> dijkstras(unordered_map<int, vector<P>> &adj, int n, int src) {
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            ll currWt    = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for (auto& nbr : adj[currNode]) {
                ll nextNode  = nbr.first;
                int nextWt   = nbr.second;

                if (dist[nextNode] > currWt + nextWt) {
                    dist[nextNode] = currWt + nextWt;
                    pq.push({(currWt + nextWt), nextNode});
                }
            }
        }
        return dist;
    }
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int E = edges.size();
        unordered_map<int, vector<P>> adj;
        
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> fromSrc  = dijkstras(adj, n, 0);       // distance from src to every other node
        vector<int> fromDest = dijkstras(adj, n, n - 1);   // distance from dest to every other node

        vector<bool> result(E, 0);
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            // x + w + y == fromSrc[n - 1] 
            // where x = dist of src to u, y = dist of dest to v
            // or    x = dist of src to v, y = dist of dest to u

            ll distFromSrc  = fromSrc[u];   // x
            ll distFromDest = fromDest[v];  // y

            if (distFromSrc + w + distFromDest == fromSrc[n - 1]) {
                result[i] = true;
            }

            // OR 
            distFromSrc  = fromSrc[v];   // x
            distFromDest = fromDest[u];  // y

            if (distFromSrc + w + distFromDest == fromSrc[n - 1]) {
                result[i] = true;
            }
        }

        return result;
    }
};