// https://leetcode.com/problems/modify-graph-edge-weights/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int LARGE_VAL = 2e9;
    typedef long long ll;
    typedef pair<ll, ll> P;

    // TC : O(E * log(V))
    // SC : O(V + E)
    ll Dijkstras(int n, vector<vector<int>>& edges, int src, int dest) {
        // make adj list without -ve weight
        unordered_map<int, vector<P>> adj;
        for (auto& edge : edges) {
            if (edge[2] != -1) {
                adj[edge[0]].push_back({edge[1], edge[2]});    // (u -> {v, w})
                adj[edge[1]].push_back({edge[0], edge[2]});
            }
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<bool> visited(n, false);
        vector<ll> shortestDist(n, INT_MAX);

        pq.push({0, src});
        shortestDist[src] = 0;   // distance from src to src is 0

        while (!pq.empty()) {
            ll currDist = pq.top().first;
            ll currNode = pq.top().second;
            pq.pop();

            if (visited[currNode]) continue;
            visited[currNode] = 1;

            for (auto& [nbr, wt] : adj[currNode]) {
                if (shortestDist[nbr] > currDist + wt) {
                    shortestDist[nbr] = currDist + wt;
                    pq.push({shortestDist[nbr], nbr});
                }
            }
        }

        return shortestDist[dest];
    }
public:
    // TC : O(E * E*log(V))
    // SC : O(V + E)
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll currSP = Dijkstras(n, edges, source, destination);  // current shortest path without -ve edges

        // if current shortest path is less than target
        if (currSP < target) return {};

        bool targetMatch = (currSP == target) ? true : false;

        for (vector<int>& edge : edges) {   // O(E)
            if (edge[2] == -1) {
                edge[2] = (targetMatch == true) ? LARGE_VAL : 1;

                if (!targetMatch) {
                    ll newSP = Dijkstras(n, edges, source, destination);    // O(E*log(V))

                    if (newSP <= target) {
                        targetMatch = true;
                        edge[2] += (target - newSP);
                    }
                }
            }
        }

        if (!targetMatch) return {};

        return edges;
    }
};