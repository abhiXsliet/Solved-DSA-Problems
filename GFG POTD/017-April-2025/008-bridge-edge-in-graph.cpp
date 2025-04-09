// https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    void DFS(int src, int parent, int &timer, unordered_map<int, vector<int>> &adj, vector<bool> &vis, vector<int> &disc, vector<int> &low, set<vector<int>> &st) {
        disc[src] = low[src] = timer ++;
        vis[src]  = true;
        
        for (int &nbr : adj[src]) {
            if (nbr == parent) 
                continue;
            else if (vis[nbr]) 
                low[src] = min(low[src], low[nbr]);    
            else {
                DFS(nbr, src, timer, adj, vis, disc, low, st);
                
                // Bridge exists
                if (disc[src] < low[nbr]) {
                    st.insert({min(src, nbr), max(src, nbr)});
                }
                
                low[src] = min(low[src], low[nbr]);
            }
        }
    }
    
    void dfs(int src, vector<bool> &visited, unordered_map<int, vector<int>> &adj) {
        visited[src] = true;
        for (int &nbr : adj[src]) {
            if (!visited[nbr]) {
                dfs(nbr, visited, adj);
            }
        }
    }
    
    // TC : O(V + E)
    // SC : O(V + E)
    bool approach_1(int V, vector<vector<int>> &edges, int c, int d) {
        unordered_map<int, vector<int>> adjOriginal, adjWithoutEdge;
        for (vector<int> edge : edges) {
            int u = edge[0], v = edge[1];
            adjOriginal[u].push_back(v);
            adjOriginal[v].push_back(u);
            if ((u == c && v == d) || (u == d && v == c)) {
                continue;
            }
            adjWithoutEdge[u].push_back(v);
            adjWithoutEdge[v].push_back(u);
        }
        
        vector<bool> visited(V, 0);
        int originalComponents = 0;
        for (int i = 0; i < V; i ++) {
            if (!visited[i]) {
                dfs(i, visited, adjOriginal);
                originalComponents += 1;
            }
        }
        
        fill(begin(visited), end(visited), 0);
        int newComponents = 0;
        for (int i = 0; i < V; i ++) {
            if (!visited[i]) {
                dfs(i, visited, adjWithoutEdge);
                newComponents += 1;
            }
        }
        return newComponents > originalComponents;
    }
        
    // TC : O(V + E)
    // SC : O(V + E)
    bool approach_2(int V, vector<vector<int>> &edges, int c, int d) {
        unordered_map<int, vector<int>> adj;
        for (vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(V, 0);
        vector<int> discover(V, 0); // first time a node is discovered
        vector<int> low(V, 0);      // reaching to node is possible in less than discovery time
        set<vector<int>> st;    // stores all the bridges
        int timer  = 0;
        int parent = -1;
        
        for (int i = 0; i < V; i ++) {
            if (!visited[i]) {
                DFS(i, parent, timer, adj, visited, discover, low, st);
            }
        }
        
        vector<int> vec = {min(c, d), max(c, d)};
        return st.count(vec);
    }
  public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // return approach_1(V, edges, c, d);  // simple : remove c-d and check if count of components increases
        return approach_2(V, edges, c, d);  // Tarjan's Algo.
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends