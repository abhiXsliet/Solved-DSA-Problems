// https://leetcode.com/problems/second-minimum-time-to-reach-destination/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    #define P pair<int, int>

    void BFS(vector<int>& d1, vector<int>& d2, int n, int change, int time,
                   unordered_map<int, vector<int>>& adj) {
        queue<P> q;    // {node, freq of visit of node}
        q.push({1, 1});
        d1[1] = 0;

        while (!q.empty()) {
            auto[node, freq] = q.front();
            q.pop();

            int timeElapsed = (freq == 1) ? d1[node] : d2[node];

            if (node == n && d2[n] != INT_MAX) // reached n destignation second time
                break;
            
            int div = timeElapsed / change;
            if (div % 2) {  // ODD : Red
                timeElapsed = change * (div + 1);
            }

            for (auto& nbr : adj[node]) {

                int newTime = timeElapsed + time;

                if (d1[nbr] == INT_MAX) {
                    d1[nbr] = newTime;
                    q.push({nbr, 1});

                } else if (d2[nbr] == INT_MAX && d1[nbr] != newTime) {
                    d2[nbr] = newTime;
                    q.push({nbr, 2});
                }
            }
        }
    }

    void Dijkstras(vector<int>& d1, vector<int>& d2, int n, int change, int time,
                   unordered_map<int, vector<int>>& adj) {
        priority_queue<P, vector<P>, greater<P>> pq;    // {timeElapsed, node}
        pq.push({0, 1});
        d1[1] = 0;

        while (!pq.empty()) {
            auto[timeElapsed, node] = pq.top();
            pq.pop();

            if (node == n && d2[n] != INT_MAX) // reached n destignation second time
                break;
            
            int div = timeElapsed / change;
            if (div % 2) {  // ODD : Red
                timeElapsed = change * (div + 1);
            }

            for (auto& nbr : adj[node]) {

                int newTime = timeElapsed + time;

                if (d1[nbr] > newTime) {
                    d2[nbr] = d1[nbr];
                    d1[nbr] = newTime;
                    pq.push({newTime, nbr});

                } else if (d2[nbr] > newTime && d1[nbr] != newTime) {
                    d2[nbr] = newTime;
                    pq.push({newTime, nbr});
                }
            }
        }
    }

    // TC : O(E * log(V))
    // SC : O(V + E)
    int approach_1(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> d1(n + 1, INT_MAX);
        vector<int> d2(n + 1, INT_MAX);

        Dijkstras(d1, d2, n, change, time, adj);
        return d2[n];   // return the distance
    }

    // TC : O(V + E)
    // SC : O(V + E)
    int approach_2(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> d1(n + 1, INT_MAX);
        vector<int> d2(n + 1, INT_MAX);

        BFS(d1, d2, n, change, time, adj);
        return d2[n];   // return the distance
    }
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // return approach_1(n, edges, time, change);  

        return approach_2(n, edges, time, change); 
    }
};