// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<int, int> P;

    void FloydWarshall(vector<vector<int>>& SPM, int n) {
        for (int via = 0; via < n; via ++) {
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < n; j ++) {
                    SPM[i][j] = min(SPM[i][j], SPM[i][via] + SPM[via][j]);
                }
            }
        }
    }

    void BellmanFord(int s, vector<int>& cityRow, vector<vector<int>>& edges, int n) {
        fill(begin(cityRow), end(cityRow), 1e9+7);
        cityRow[s] = 0;

        for (int i = 1; i < n; i ++) {
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (cityRow[u] != 1e9+7 && cityRow[u] + w < cityRow[v]) {
                    cityRow[v] = cityRow[u] + w;
                }

                if (cityRow[v] != 1e9+7 && cityRow[v] + w < cityRow[u]) {
                    cityRow[u] = cityRow[v] + w;
                }
            }
        }
    }

    // TC : O(V+E(logV))
    // SC : O(V) for storing the distance array 
    void Dijkstra(int src, vector<int>& cityRow, unordered_map<int, vector<P>>& adj, int n) {
        priority_queue<P, vector<P>, greater<P>> pq;
        fill(begin(cityRow), end(cityRow), INT_MAX);
        
        cityRow[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int d    = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& it : adj[node]) {
                int adjNode = it.first;
                int dist    = it.second;

                if (d + dist < cityRow[adjNode]) {
                    cityRow[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }
    }

    // TC : O(V^2) Where V = No. of vertices
    int getResultantCity(int n, vector<vector<int>>& SPM, int distanceThreshold) {
        int leastReachCnt = n;
        // City with the minimum number of reachable city with threshold distance
        int resultantCity = -1;

        for (int i = 0; i < n; i ++) {  // O(V^2)
            int cntReach = 0;
            for (int j = 0; j < n; j ++) {
                if (i != j && SPM[i][j] <= distanceThreshold) {
                    cntReach ++;
                }
            }
            if (cntReach <= leastReachCnt) {
                leastReachCnt = cntReach;
                resultantCity = i;
            }
        }

        return resultantCity;
    }

    // TC : O(V * E* log(V)), where n is the number of nodes
    // SC : O(V^2)            for storing the SPM (shortest path matrix)
    int solve_approach_1(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // create a shortest path matrix
        vector<vector<int>> SPM(n, vector<int>(n, 1e9+7));    // O(V^2)
        
        for (int i = 0; i < n; i ++) {
            SPM[i][i] = 0;
        }

        // create adjacency list
        unordered_map<int, vector<P>> adj;  // O(V + E)

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        for (int city = 0; city < n; city++) {  // O(V*E*log(V)) ---------> worst : O(V^3 * log(V))
                                                // E = V*(V - 1) / 2 => O(V^2)
            Dijkstra(city, SPM[city], adj, n);
        }
        
        // find the city with minimum no. of reachable city within threshold dist
        return getResultantCity(n, SPM, distanceThreshold);
    }

    // TC : O(V * E* log(V)), where n is the number of nodes
    // SC : O(V^2)            for storing the SPM (shortest path matrix)
    int solve_approach_2(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // create a shortest path matrix
        vector<vector<int>> SPM(n, vector<int>(n, 1e9+7));    // O(V^2)
        
        for (int i = 0; i < n; i ++) {
            SPM[i][i] = 0;
        }

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            SPM[u][v] = w;
            SPM[v][u] = w;
        }

        // O(V * V * E) ~= O(V*V*V*V) ~= O(V^4) sice E is prop. to V^2
        for (int city = 0; city < n; city++) {  // O(V)
            BellmanFord(city, SPM[city], edges, n); // O(V*E)
        }
        
        // find the city with minimum no. of reachable city within threshold dist
        return getResultantCity(n, SPM, distanceThreshold);
    }

    // TC : O(N^3)
    // SC : O(N^2)
    int solve_approach_3(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // create a shortest path matrix
        vector<vector<int>> SPM(n, vector<int>(n, 1e9+7));    // O(V^2)
        
        for (int i = 0; i < n; i ++) {
            SPM[i][i] = 0;
        }

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            SPM[u][v] = w;
            SPM[v][u] = w;
        }

        FloydWarshall(SPM, n);
        
        // find the city with minimum no. of reachable city within threshold dist
        return getResultantCity(n, SPM, distanceThreshold);
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // return solve_approach_1(n, edges, distanceThreshold);   // DIJKSTRA's 

        // return solve_approach_2(n, edges, distanceThreshold);   // BELLMANFORD

        return solve_approach_3(n, edges, distanceThreshold);   // FLOYD WARSHAL
    }
};