// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    #define P pair<int, int>
    
    void prepareAdj(vector<vector<int>>& edges, unordered_map<int, vector<int>>& adj) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
    // TC : O(N + M)
    // SC : O(N + M) Where N = Vertices & M = Edges
    vector<int> approach_1(vector<vector<int>>& edges, int N, int M, int src) {
        unordered_map<int, vector<int>> adj;
        prepareAdj(edges, adj);
        
        vector<int> result(N, -1);
        vector<bool> visited(N, 0);
        
        // APPLY BFS
        queue<pair<int, int>> q;    // {node, dist}
        q.push({src, 0});
        visited[src] = 1;
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int dist = it.second;
            
            result[node] = dist;
            
            for (auto& nbr : adj[node]) {
                if (!visited[nbr]) {
                    q.push({nbr, dist + 1});
                    visited[nbr] = 1;
                }
            }
        }
        
        return result;
    }
    
    // TC : O((N + M) * log(N))
    // SC : O(N + M)
    vector<int> approach_2(vector<vector<int>>& edges, int N, int M, int src) {
        unordered_map<int, vector<int>> adj;
        prepareAdj(edges, adj);
        
        vector<int> dist(N, INT_MAX);
        dist[src] = 0;
        
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, src});
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int u = it.second;
            int d = it.first;
            
            for (int v : adj[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    pq.push({dist[v], v});
                }
            }
        }
        
        for (int& d : dist) {
            if (d == INT_MAX)
                d = -1;
        }
        
        return dist;
    }
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // return approach_1(edges, N, M, src);    // BFS
        
        return approach_2(edges, N, M, src);    // Dijkstras
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}
// } Driver Code Ends