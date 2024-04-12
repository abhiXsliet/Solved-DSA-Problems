// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    // TC : O(V + E)
    // SC : O(V)
    bool dfsCyclic(int src, vector<int> adj[], vector<bool>& vis, vector<bool>& inRec) {
        vis[src]   = 1;
        inRec[src] = 1;
        for (auto& nbr : adj[src]) {
            if (!vis[nbr] && dfsCyclic(nbr, adj, vis, inRec)) {
                return true;
            }
            else if (inRec[nbr]) {  // cycle : vis[node] = 1 && inRec[node] = 1
                return true;
            }
        }
        inRec[src] = 0; // mark false as recursive call gets completed
        return false;
    }
    
    // TC : O(V + E)
    // SC : O(V)
    bool solve_approach_1(int V, vector<int> adj[]) {
        vector<bool> vis(V, 0);
        vector<bool> inRecursion(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i] && dfsCyclic(i, adj, vis, inRecursion)) {
                return true;
            }
        }
        return false;
    }
    
    // TC : O(V + E)
    // SC : O(V)
    bool solve_approach_2(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int& nbr : adj[i]) {
                indegree[nbr] ++;
            }
        }
        
        queue<int> q;
        // push those nodes in queue whose indegree is zero
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) 
                q.push(i);
        }
        
        int cntNodes = 0;
        while(!q.empty()) {
            int fNode = q.front();
            q.pop();
            cntNodes ++;
            
            for (int& nbr : adj[fNode]) {
                indegree[nbr] --;
                
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        
        if (cntNodes == V) {    // able to visit all nodes 
            return 0;   // no cycle
        }
        return 1;   // Cycle since not able to visit all nodes
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // return solve_approach_1(V, adj);     // DFS
        
        return solve_approach_2(V, adj);     // BFS : Kahn's Algo (DAG) -> (topo sort using bfs)
                                             // if topo sort possible then no cycle otherwise cycle present
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends