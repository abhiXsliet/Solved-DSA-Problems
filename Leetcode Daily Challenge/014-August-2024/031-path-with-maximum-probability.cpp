// https://leetcode.com/problems/path-with-maximum-probability/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<double, int> P;

    void Dijkstras(int src, unordered_map<int, vector<P>>& adj, vector<double>& probToReachDest) {
        priority_queue<P> pq;
        pq.push({1.0, src});  // 100% prob to reach src from src

        while (!pq.empty()) {
            auto pair   = pq.top();
            pq.pop();

            double prob = pair.first;
            int node    = pair.second;

            for (auto& nbr : adj[node]) {
                double newProb = nbr.first;
                int newNode    = nbr.second;
                
                if (probToReachDest[newNode] < prob * newProb) {
                    probToReachDest[newNode] = prob * newProb;
                    pq.push({probToReachDest[newNode], newNode});
                }
            }
        }
    }
public:
    // TC : O(E * log(V))
    // SC : O(V + E)
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<P>> adj;
        for (int i = 0; i < edges.size(); i ++) {
            int u    = edges[i][0];
            int v    = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
        
        // Min prob to reach destination from src for every node is 0
        vector<double> probToReachDest(n, 0.0);  

        Dijkstras(start_node, adj, probToReachDest);

        return probToReachDest[end_node];
    }
};