// https://www.geeksforgeeks.org/problems/minimum-weight-cycle/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    typedef pair<int, int> P;
    
    // TC : O((V + E)log(V))
    int dijkstras(int V, unordered_map<int, vector<P>> &adj, int src, int dest) {
        vector<int> distance(V, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, src});
        distance[src] = 0;
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (d > distance[u]) continue;
            
            for (auto &nbr : adj[u]) {
                int v = nbr.first;
                int dist = nbr.second;
                
                if ((u == src && v == dest) || (u == dest && v == src)) continue;
                
                if (distance[v] > d + dist) {
                    distance[v] = d + dist;
                    pq.push({distance[v], v});
                }
            }
        }
        return distance[dest];
    }
    
    // TC : O(V!) 
    // SC : O(V) Recursive Depth
    bool dfs(int u, int parent, unordered_map<int, vector<P>> &adj, vector<bool> &visited, int pathSum, int &minCycleWt) {
        visited[u] = true;
        bool foundCycle = false;
        for (auto &nbr : adj[u]) {
            int v  = nbr.first;
            int wt = nbr.second;
            
            if (!visited[v]) {
                if(dfs(v, u, adj, visited, pathSum + wt, minCycleWt))
                    foundCycle = true;
            } else if (v != parent) {   // cycle found
                minCycleWt = min(minCycleWt, pathSum + wt);
                foundCycle = true;
            }
        }
        visited[u] = false;
        return foundCycle;
    }
    
    void prepareAdj(vector<vector<int>> &edges, unordered_map<int, vector<P>> &adj) {
        for (vector<int> &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
    }
    
    // TC : O(V!) 
    // SC : O(V + E)
    int approach_1(int v, vector<vector<int>> &edges) {
        unordered_map<int, vector<P>> adj;
        prepareAdj(edges, adj);
        vector<bool> visited(v, 0);
        
        int minCycleWt = INT_MAX;
        for (int i = 0; i < v; i ++) {
            dfs(i, -1, adj, visited, 0, minCycleWt);
        }
        return minCycleWt;
    }
    
    // TC : O(E * (V + Elog(V)))
    // SC : O(V + E)
    int approach_2(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<P>> adj;
        prepareAdj(edges, adj);
        
        int minCycle = INT_MAX;
        for (const vector<int> &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2]; // remove this current edge and add this later
            
            int shortestDist = dijkstras(V, adj, u, v);
            if (shortestDist != INT_MAX) {
                minCycle = min(minCycle, wt + shortestDist);
            }
        }
        return minCycle;
    }
  public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        // return approach_1(V, edges);    // DFS : get all cycles path and choose the minimum one
    
        return approach_2(V, edges);    // remove each edge(u-v) and find shortest path from u-v
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }

        Solution obj;
        int res = obj.findMinCycle(V, edges);

        cout << res << endl;
    }

    return 0;
}
// } Driver Code Ends