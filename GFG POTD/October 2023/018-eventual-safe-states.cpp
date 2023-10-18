// https://practice.geeksforgeeks.org/problems/eventual-safe-states/1


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[], int check[]) {
        vis[node]     = 1;
        pathVis[node] = 1;
        check[node]   = 0;
        
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathVis, check) == true)
                    return true;
            }
            else if (pathVis[it]) {
                return true;
            }
        }
        
        check[node]   = 1;
        pathVis[node] = 0;
        return false;
    }
    
    // TC = O(V + E)
    // SC = O(V)
    vector<int> solve_approach_1_dfs(int V, vector<int> adj[]) {
        int vis[V]     = {0};
        int pathVis[V] = {0};
        int check[V]   = {0};
        
        vector<int> safeNodes;
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfsCheck(i, adj, vis, pathVis, check);
            }
        }
        
        for (int i = 0; i < V; i++) {
            if (check[i] == 1)
                safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
    
    
    vector<int> solve_approach_2_topoSort(int V, vector<int> adj[]) {
        vector<int> adjRev[V];
        int indegree[V] = {0};
        
        for (int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                adjRev[it].push_back(i); // reverse the edges it -> i
                indegree[i]++;
            }
        }
        
        queue<int> q;
        vector<int> safeNodes;
        for(int i = 0; i < V; i++) {
            if (indegree[i] == 0) 
                q.push(i);
        }
        
        //BFS
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            safeNodes.push_back(node);
            for(auto it : adjRev[node]) {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        
        sort(begin(safeNodes), end(safeNodes));
        return safeNodes;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // return solve_approach_1_dfs(V, adj);
        
        
        return solve_approach_2_topoSort(V, adj);
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

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends