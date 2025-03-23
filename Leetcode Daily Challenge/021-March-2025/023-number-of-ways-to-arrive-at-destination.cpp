// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long int ll;
    typedef pair<ll, int> P;
    const int M = 1e9 + 7;

    // TC : O((E + V) * log(V))
    // SC : O(N)
    void dijkstras(int n, unordered_map<int, vector<P>> &adj, vector<ll>& countWays, int src) {
        vector<ll> dist(n, LONG_MAX);
        dist[src]  = 0;
        countWays[src] = 1;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            ll currTime  = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for (auto &nbr : adj[currNode]) {
                ll nbrTime  = nbr.second;
                int nbrNode = nbr.first;

                if (currTime + nbrTime < dist[nbrNode]) {
                    dist[nbrNode] = currTime + nbrTime;
                    countWays[nbrNode] = countWays[currNode];
                    pq.push({dist[nbrNode], nbrNode});
                    
                } else if (currTime + nbrTime == dist[nbrNode]) {
                    countWays[nbrNode] = (countWays[nbrNode] + countWays[currNode]) % M;
                }
            }
        }
    }
public:
    // TC : O(E*log(V))
    // SC : O(N)
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<P>> adj;
        for (vector<int> road : roads) {
            int u = road[0];
            int v = road[1];
            int t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<ll> countWays(n, 0);
        dijkstras(n, adj, countWays, 0);

        return countWays[n - 1];
    }
};