// https://leetcode.com/contest/biweekly-contest-125/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    
    ll getPairs(int node, int distance, int ss, int parent, unordered_map<int, vector<pair<int, int>>>& adj) {
        ll ans = 0;
        
        if (distance % ss == 0) ans ++;

        for (auto& neigh : adj[node]) {
            if (neigh.first == parent) 
                continue;
            ans += getPairs(neigh.first, neigh.second + distance, ss, node, adj);
        }
        return ans;
    }
    
    int findPairs(int node, unordered_map<int, vector<pair<int, int>>>& adj, int ss, int parent) {
        ll child_sum  = 0;   
        ll pairs      = 0;
        for (auto& neigh : adj[node]) {
            int neighNode = neigh.first;
            int weight    = neigh.second;
            
            // child nodes cnt c1, c2, c3, .... which are good nodes (i.e, divisible by ss)
            ll child_cnt  = getPairs(neighNode, weight, ss, node, adj); 
            
            // make no. of pairs mathematically 
            // for 2-childs : c1, c2         => pairs : c1 * c2
            // for 3-childs : c1, c2, c3     => pairs : c3 * (c1 + c2)
            // for 4-childs : c1, c2, c3, c4 => pairs : c4 * (c1 + c2 + c3) so on ...
            pairs      += child_cnt * child_sum;
            child_sum  += child_cnt;
        }
        return pairs;
    }
    
    void prepareAdj(vector<vector<int>>& edges, unordered_map<int, vector<pair<int, int>>>& adj) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }
public:
    // TC : O(N * E) Where N = No. of vertices & E = No. of edges
    // SC : O(N + E)
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;   // no. of vertices
        // prepare adjacenty list
        unordered_map<int, vector<pair<int, int>>> adj(n);
        prepareAdj(edges, adj);

        // store no. of pairs which are connectable through server i
        vector<int> ans(n, 0);
        
        for (int i = 0; i < n; i++) {
            ans[i] = findPairs(i, adj, signalSpeed, -1);
        }
        return ans;
    }
};