// https://www.geeksforgeeks.org/problems/articulation-point2616/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    void DFS(int src, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<bool> &vis, vector<int> &articulations, unordered_map<int, vector<int>> &adj) {
        disc[src] = low[src] = timer ++;
        vis[src]  = true;
        int child = 0;
        
        for (int &nbr : adj[src]) {
            if (nbr == parent) 
                continue;
            else if (vis[nbr]) 
                low[src] = min(low[src], disc[nbr]);
            else {
                child += 1;
                
                DFS(nbr, src, timer, disc, low, vis, articulations, adj);
                
                if (disc[src] <= low[nbr] && parent != -1) {
                    articulations[src] = true;
                }
                
                low[src] = min(low[src], low[nbr]); // catch
            }
        }
        
        if (parent == -1 && child > 1) {    // condn for root node to be an articulation point
            articulations[src] = true;
        }
    }
  public:
    // TC : O(V + E)
    // SC : O(V + E)
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (vector<int> &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> discovery(V, 0);   // initital time of discovery of node
        vector<int> lowestTime(V, 0);   // lowest time of discovery of node
        vector<bool> visited(V, 0);
        vector<int> articulations(V, 0);
        int timer = 0;
        
        for (int i = 0; i < V; i ++) {
            if (!visited[i]) {
                DFS(i, -1, timer, discovery, lowestTime, visited, articulations, adj);
            }
        }
        
        vector<int> result;
        for (int i = 0; i < V; i ++) {
            if (articulations[i]) {
                result.push_back(i);
            }
        }
        return result.empty() ? vector<int>{-1} : result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends