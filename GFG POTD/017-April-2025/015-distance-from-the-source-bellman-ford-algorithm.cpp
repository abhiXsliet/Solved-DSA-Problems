// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // TC : O(V * E)
    // SC : O(V)
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        // Step-1 : Processing each node (v - 1) times
        for (int i = 0; i < V - 1; i ++) {
            for (vector<int> &edge : edges) {
                int u = edge[0], v = edge[1], wt = edge[2];
                if (dist[u] == 1e8) continue;
                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Step-2 : Processing each node one more time to check -ve cycle if there's updation in distance array
        for (vector<int> &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            if (dist[u] == 1e8) continue;
            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                return {-1};  // negative cycle detected
            }
        }
        return dist;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int> > edges;

        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(V, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends