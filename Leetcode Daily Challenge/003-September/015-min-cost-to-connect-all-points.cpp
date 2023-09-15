// https://leetcode.com/problems/min-cost-to-connect-all-points/


#include <bits/stdc++.h>
using namespace std;

// TC = O(E * log(E)) where E = edges
// SC = O(V * V)
class Solution {
    typedef pair<int, int> P;
private:
    int primsAlgo(vector<vector<P>>& adj, int V) {
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, 0}); // wt, node

        vector<bool> inMst(V, 0);
        int sum = 0;

        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int wt   = p.first;
            int node = p.second;

            if (inMst[node]) continue;

            inMst[node] = 1;
            sum += wt;

            for (auto& vec : adj[node]) { 
                int neighbour = vec.first;
                int neigh_wt  = vec.second;

                if(inMst[neighbour] == 0)
                    pq.push({neigh_wt, neighbour});
            }
        }

        return sum;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<P>> adj(V);
        
        // prepare adj
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                
                int x1 = points[i][0];
                int y1 = points[i][1];
                
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, dist}); // dist of i from j
                adj[j].push_back({i, dist}); // dist of j from i
            }
        }

        return primsAlgo(adj, V);
    }
};