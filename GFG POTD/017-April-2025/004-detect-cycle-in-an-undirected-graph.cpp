// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class DSU {
  public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i ++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    // TC : Amortized O(α(n)).
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        
        return parent[x] = findParent(parent[x]);   // path compression
    }
    
    // TC : O(α(n)).
    void doUnion(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        
        if (rank[u] < rank[v]) {
            parent[u] = v;
            rank[v]  += 1;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
            rank[u]  += 1;
        } else {
            parent[v] = u;
            rank[u]  += 1;
        }
    }
};

class Solution {
  private:
    bool bfs(int src, int parent, unordered_map<int, vector<int>> &adj, vector<bool> &visited) {
        queue<pair<int,int>> q; // {node, parent}
        q.push({src, parent});
        visited[src] = 1;
        while (!q.empty()) {
            int fNode   = q.front().first;
            int fParent = q.front().second;
            q.pop();
            
            for (int &nbr : adj[fNode]) {
                if (!visited[nbr]) {
                    q.push({nbr, fNode});
                    visited[nbr] = 1;
                } else if (nbr != fParent) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(int src, int parent, unordered_map<int, vector<int>> &adj, vector<bool> &visited) {
        visited[src] = 1;
        for (int &nbr : adj[src]) {
            if (!visited[nbr]) {
                if (dfs(nbr, src, adj, visited)) 
                    return true;
            } else if (nbr != parent) {
                return true;
            }
        }
        return false;
    }
    
    unordered_map<int, vector<int>> prepareAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }
    
    // TC : O(V + E)
    // SC : O(V + E)
    bool approach_1(int v, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj = prepareAdj(edges);
        vector<bool> visited(v, 0);
        for (int i = 0; i < v; i ++) {
            if (!visited[i] && dfs(i, -1, adj, visited)) {
                return true;
            }
        }
        return false;
    }

    // TC : O(V + E)
    // SC : O(V + E)
    bool approach_2(int v, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj = prepareAdj(edges);
        vector<bool> visited(v, 0);
        for (int i = 0; i < v; i ++) {
            if (!visited[i] && bfs(i, -1, adj, visited)) {
                return true;
            }
        }
        return false;
    }
    
    // TC : O(V + E * α(N)) where α(N) is the inverse Ackermann function, which grows extremely slowly and can be considered constant for all practical purposes
    // SC : O(V + E)
    bool approach_3(int N, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj = prepareAdj(edges);
        DSU d(N);
        
        for (int u = 0; u < N; u ++) {
            for (int &v : adj[u]) {
                if (u < v) {
                    int u_parent = d.findParent(u);
                    int v_parent = d.findParent(v);
                    if (u_parent == v_parent) 
                        return true;
                    d.doUnion(u, v);    // if u & v are in different set, brings them together in the same set
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // return approach_1(V, edges); // DFS
        // return approach_2(V, edges); // BFS
        return approach_3(V, edges); // DSU
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends