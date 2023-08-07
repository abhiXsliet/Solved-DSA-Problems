// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    void dfs(int node, unordered_map<int, bool> &visited,
            unordered_map<int, list<pair<int, int>>> &adj, stack<int> &s) {
        visited[node] = 1;
        for(auto neigh : adj[node]) {
            if(!visited[neigh.first]) {
                dfs(neigh.first, visited, adj, s);
            }
        }
        s.push(node);
    }
    
    void getShortestPath(int src, vector<int>& dist,
                        unordered_map<int, list<pair<int, int>>>& adj, stack<int>& s) {
        dist[src] = 0;
        
        while(!s.empty()) {
            int topNode = s.top();
            s.pop();
            
            for(auto neigh : adj[topNode]) {
                if(dist[topNode] + neigh.second < dist[neigh.first]) {
                    dist[neigh.first] = dist[topNode] + neigh.second;
                }
            }
        }
    }
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        //prepare adjacency list
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v, wt});
        }
        // find topological sort
        unordered_map<int, bool> visited;
        stack<int>s;
        for(int i = 0; i < N; i++) {
            if(!visited[i]) {
                dfs(i, visited, adj, s);
            }
        }
        // get shortest distance
        int src = 0;
        vector<int> dist(N, 1e9);
        getShortestPath(src, dist, adj, s);
        
        for(int i = 0; i < dist.size(); i++) 
            if(dist[i] == 1e9) dist[i] = -1;
            
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends