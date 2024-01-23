// https://www.geeksforgeeks.org/problems/course-schedule/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  private:
    vector<int> checkTopoSort(unordered_map<int, vector<int>>& adj, vector<int>& indegree) {
        queue<int> q;
        vector<int> ans;
        
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int fNode = q.front();
            q.pop();
            ans.push_back(fNode);
            for (auto& neigh : adj[fNode]) {
                indegree[neigh]--;
                
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        return ans;
    }
    
    bool dfs(int node, vector<int>& visited, unordered_map<int, vector<int>>& adj, vector<int>& ans) {
        visited[node] = 1;
        for (auto& neigh : adj[node]) {
            if(!visited[neigh]) {
                if(!dfs(neigh, visited, adj, ans))
                    return false;
            }
            else if (visited[neigh] == 1)
                return false;
        }
        visited[node] = 2;
        ans.push_back(node);
        return true;
    }
    
    // TC : O(M + N) , where M is the number of vertices (courses) and N is the number of edges (prerequisites)
    // SC : O(M + N)
    vector<int> solve_bfs(int n, int m, vector<vector<int>> prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n);
        
        for (auto& pre : prerequisites) {
            int u = pre[0];
            int v = pre[1];
            
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        vector<int>ans = checkTopoSort(adj, indegree);
        if (ans.size() < n) return {};
        return ans;
    }
    
    // TC : O(M + N) , where M is the number of vertices (courses) and N is the number of edges (prerequisites)
    // SC : O(M + N)
    vector<int> solve_dfs(int n, int m, vector<vector<int>> prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> visited(n, 0);
        for (auto& pre : prerequisites) {
            int u = pre[0];
            int v = pre[1];
            adj[v].push_back(u);
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if(!dfs(i, visited, adj, ans)) {
                    return {}; // Returns Empty vector if cycle is detected
                }
            }
        }
        
        if (ans.size() < n) return {};
        reverse(begin(ans), end(ans));  
        return ans;
    }
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        // return solve_bfs(n, m, prerequisites);
        
        return solve_dfs(n, m, prerequisites);
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends