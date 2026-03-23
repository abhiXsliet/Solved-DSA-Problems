// https://www.geeksforgeeks.org/problems/length-of-longest-cycle-in-a-graph/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    int result = -1;
    void dfs(int u, vector<bool>& visited, vector<bool>& inRecursion, vector<int> &count, vector<int> &edge) {
        if (u == -1) return;
        
        visited[u] = 1;
        inRecursion[u] = 1;
        
        int v = edge[u];
        
        if (v != -1 && !visited[v]) {
            count[v] = count[u] + 1;
            dfs(v, visited, inRecursion, count, edge);
            
        } else if (v != -1 && inRecursion[v]) {
            result = max(result, count[u] - count[v] + 1);
        }
        
        inRecursion[u] = 0;
    }
  public:
    // TC : O(V + E)
    // SC : O(V + E)
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> edge(V, -1);
        for (vector<int> &e : edges) {
            edge[e[0]] = e[1];
        }
        vector<bool> visited(V, 0), inRecursion(V, 0);
        vector<int> count(V, 1);
        
        for (int i = 0; i < V; i ++) {
            if (!visited[i]) {
                dfs(i, visited, inRecursion, count, edge);
            }
        }
        
        return result;
    }
};