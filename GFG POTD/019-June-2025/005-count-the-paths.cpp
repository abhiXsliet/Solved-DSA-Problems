// https://www.geeksforgeeks.org/problems/count-the-paths4332/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int bfs(vector<vector<int>> &adj, vector<int> &deg, int src, int dest) {
        int V = deg.size();
        vector<int> storeWays(V, 0);
        queue<int> q;
        storeWays[src] = 1;
    
        for (int i = 0; i < V; i++) {
            if (!deg[i]) q.push(i);
        }
    
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            
            for (int &v : adj[u]) {
                storeWays[v] += storeWays[u];
                
                deg[v]--;
                
                if (!deg[v]) q.push(v);
            }
        }
    
        return storeWays[dest];
    }
    
    int dfs(vector<vector<int>> &adj, int src, int dest, unordered_map<int, int> &memo) {
        if (src == dest) {
            return 1;
        }
        if (memo.count(src)) return memo[src];
        int ways = 0;
        for (int &nbr : adj[src]) {
            ways += dfs(adj, nbr, dest, memo);
        }
        return memo[src] = ways;
    }
    
  public:
    // TC : O(V + E)
    // SC : O(V + E)
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        for (vector<int> &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]] ++;
        }
        
        unordered_map<int, int> memo;
        return dfs(adj, src, dest, memo);
        
        // return bfs(adj, indegree, src, dest);
    }
};