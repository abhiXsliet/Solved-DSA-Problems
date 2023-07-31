// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    void bfs(int node, int V, vector<int> adj[], vector<int>& ans) {
        queue<int> q;
        q.push(node);
        vector<bool>visited(V, 0);
        visited[node] = 1;
        
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            for(auto& i: adj[frontNode]) {
                if(!visited[i]) {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }

public:
    // Function to return Breadth First Traversal of the given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        bfs(0, V, adj, ans);
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
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends