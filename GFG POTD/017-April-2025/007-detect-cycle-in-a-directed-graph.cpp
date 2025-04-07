// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  private:
    bool dfs(int src, vector<bool> &visited, vector<bool> &inRecur, unordered_map<int, vector<int>> &adj) {
        visited[src] = true;
        inRecur[src] = true;
        for (int &nbr : adj[src]) {
            if (!visited[nbr]) {
                if (dfs(nbr, visited, inRecur, adj)) {
                    return true;
                }
            } else if (inRecur[nbr]) {
                return true;
            }
        }
        inRecur[src] = false;
        return false;
    }
    
    // TC : O(V + E)
    // SC : O(V + E)
    bool approach_1(int v, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        for (vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<bool> visited(v, 0);
        vector<bool> inRecursion(v, 0);
        
        for (int i = 0; i < v; i ++) {
            if (!visited[i] && dfs(i, visited, inRecursion, adj)) {
                return true;
            }
        }
        return false;
    }

    // TC : O(V + E)
    // SC : O(V + E)
    bool approach_2(int v, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(v, 0);
        for (vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]] ++;
        }
        
        vector<bool> visited(v, 0);
        queue<int> q;
        
        for (int i = 0; i < v; i ++) {
            if (!indegree[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
        
        vector<int> topoSort;
        while (!q.empty()) {
            int fNode = q.front();
            q.pop();

            topoSort.push_back(fNode);
            for (int &nbr : adj[fNode]) {
                indegree[nbr] --;
                if (!indegree[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
        
        return topoSort.size() != v;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // return approach_1(V, edges); // DFS
        return approach_2(V, edges); // Kahn's Algo. : BFS
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
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends