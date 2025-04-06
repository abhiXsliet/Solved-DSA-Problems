// https://www.geeksforgeeks.org/problems/topological-sort/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    void dfs(int src, vector<bool> &visited, stack<int> &stk, unordered_map<int, vector<int>> &adj) {
        visited[src] = 1;
        for (auto &nbr : adj[src]) {
            if (!visited[nbr]) {
                dfs(nbr, visited, stk, adj);
            }
        }
        stk.push(src);
    }
    
    // TC : O(V + E)
    // SC : O(V)
    vector<int> approach_1(int v, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(v, 0);
        for (vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]] ++;
        }
        
        queue<int> q;
        for (int i = 0; i < v; i ++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        
        vector<int> result;
        while (!q.empty()) {
            int n = q.size();
            while (n --) {
                int fNode = q.front();
                q.pop();
                
                result.push_back(fNode);
                
                for (int &nbr : adj[fNode]) {
                    indegree[nbr] --;
                    if (!indegree[nbr]) {
                        q.push(nbr);
                    }
                }
            }
        }
        
        return result;
    }
    
    // TC : O(V + E)
    // SC : O(V)
    vector<int> approach_2(int v, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        for (vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        stack<int> stk;
        vector<bool> visited(v, 0);
        
        for (int i = 0; i < v; i ++) {
            if (!visited[i]) {
                dfs(i, visited, stk, adj);
            }
        }
        
        vector<int> result;
        while (!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // return approach_1(V, edges);  // BFS : Kahn's Algo
        return approach_2(V, edges);    // DFS
    }
};


//{ Driver Code Starts.
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(V, res, adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends