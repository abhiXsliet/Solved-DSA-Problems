// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  private:
    // TC : O(V + E)
    // SC : O(V) -> Recursive Depth
    bool dfs(int src, int parent, vector<bool>& vis, vector<int> adj[]) {
        vis[src] = 1;
        for (auto& nbr : adj[src]) {
            if (!vis[nbr]) {
                if (dfs(nbr, src, vis, adj))
                    return true;
            }
            else if (nbr != parent) {   // vis[node] = 1 && node != parent
                return true;
            }
        }
        return false;
    }
    
    // TC : O(V + E)
    // SC : O(V)
    bool bfs(int src, vector<bool>& vis, vector<int> adj[]) {
        queue<pair<int, int>> q; // {node, parent}
        q.push({src, -1});
        vis[src] = 1;
        while(!q.empty()) {
            int fNode  = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto nbr : adj[fNode]) {
                if (!vis[nbr]) {
                    vis[nbr] = 1;
                    q.push({nbr, fNode});   // now nbr ----> parent = fNode
                }
                else if (parent != nbr) { // visited && parent != nbr
                    return true;
                }
            }
        }
        return false;
    }
    
    // TC : O(V + E)
    // SC : O(V)    
    bool solve_dfs(int V, vector<int> adj[]) {
        vector<bool> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i] && dfs(i, -1, vis, adj)) {
                return true;
            }
        }
        return false;
    }
    
    // TC : O(V + E)
    // SC : O(V)    
    bool solve_bfs(int V, vector<int> adj[]) {
        vector<bool> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i] && bfs(i, vis, adj)) {
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // return solve_dfs(V, adj);
        
        return solve_bfs(V, adj);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends