// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  private:
    void dfs(int node, unordered_map<int, bool>& visited, 
                vector<int> adj[], vector<int>& ans) {
        ans.push_back(node);
        visited[node] = 1;
        
        for(auto neigh : adj[node]) {
            if(!visited[neigh]) {
                dfs(neigh, visited, adj, ans);
            }
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited;
        vector<int> ans;
        
        //Traverse for each components
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, visited, adj, ans);
            }
        }
        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends