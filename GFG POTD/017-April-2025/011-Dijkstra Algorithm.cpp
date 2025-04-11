// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User Function Template
class Solution {
  private:
    typedef pair<int, int> P;
    
    void dijkstras(int src, unordered_map<int, vector<P>> &adj, vector<int> &distance ) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, src});
        distance[src] = 0;
        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            for (auto &it : adj[node]) {
                int nbrNode = it.first;
                int nbrDist = it.second;
                
                if (nbrDist + dist < distance[nbrNode]) {
                    distance[nbrNode] = nbrDist + dist;
                    pq.push({distance[nbrNode], nbrNode});
                }
            }
        }
    }
  public:
    // TC : O((V + E)*log(V))
    // SC : O(V + E)
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        unordered_map<int, vector<P>> adj;
        for (vector<int> edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> distance(V, INT_MAX);
        dijkstras(src, adj, distance);
        return distance;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends