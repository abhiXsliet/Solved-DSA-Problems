// https://leetcode.com/problems/cheapest-flights-within-k-stops/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<int, int> P;

    void prepare(vector<vector<int>>& flights, int n, unordered_map<int, list<P>> &adj) {
        for (auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int p = flight[2];

            adj[u].push_back({v, p});
        }
    }

    // TC : O(E + V), where E is the number of edges (flights) and V is the number of vertices (cities)
    // SC : O(V)
    void BFS(vector<vector<int>>& flights, int n, unordered_map<int, list<P>>& adj, 
            int src, int dst, int k, vector<int>& dist) {
        queue<P> q;
        
        q.push({src, 0});
        dist[src] = 0;

        int steps = 0;
        while (!q.empty() && steps <= k) {
            
            int size = q.size();
            while (size --) {
                int node = q.front().first;
                int cost = q.front().second;
                q.pop();

                for (auto& neigh : adj[node]) {
                    int n = neigh.first;
                    int c = neigh.second;

                    if (dist[n] > cost + c) {
                        dist[n] = cost + c;

                        q.push({n, cost + c}); 
                    }
                }
            }
            steps ++;
        }
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, list<P>> adj;
        // prepare adjacency list
        prepare(flights, n, adj);

        vector<int> distance(n, INT_MAX);

        BFS(flights, n, adj, src, dst, k, distance);

        if (distance[dst] == INT_MAX) 
            return -1;
        return distance[dst];
    }
};