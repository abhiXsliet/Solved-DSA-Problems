// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    typedef pair<int, int> P;
    
    void Dijkstras(int src, int dest, unordered_map<int, vector<pair<int, int>>>& adj, 
                   vector<int>& dist, vector<int>& parent) {
        priority_queue<P, vector<P>, greater<P>> pq;
        dist[src] = 0;
        pq.push({0, src});  // {dist, node} pq sorts on basis of distance
        
        while (!pq.empty()) {
            int fDist = pq.top().first;
            int fNode = pq.top().second;
            pq.pop();
            
            for (auto& nbr : adj[fNode]) {
                int nbrDist = nbr.second;
                int nbrNode = nbr.first;
                
                if (dist[nbrNode] > fDist + nbrDist) {
                    dist[nbrNode] = fDist + nbrDist;
                    pq.push({dist[nbrNode], nbrNode}); 
                    parent[nbrNode] = fNode;
                }
            }
        }
    }
  public:
    // TC : O(m * log(n))
    // SC : O(n + m)
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        unordered_map<int, vector<P>>adj;
        // prepare adj list
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1, -1);
        
        Dijkstras(1, n, adj, dist, parent);
        
        if (dist[n] == INT_MAX) 
            return {-1};
        
        vector<int> path;
        int node = n;
        while (node != -1) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(dist[n]);    
        reverse(path.begin(), path.end());

        return path;
    }
};


//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}
// } Driver Code Ends