// https://www.geeksforgeeks.org/problems/number-of-good-components--170647/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};
// } Driver Code Ends

class Solution {
  private:
    // TC : O(V + E)
    // SC : O(Depth of Recursion) -> O(V)
    void dfs(int src, unordered_map<int, vector<int>>& adj, 
             vector<bool>& vis, int& cntV, int& cntE) {
        vis[src] = 1;
        cntV    += 1;
        cntE    += adj[src].size();
        
        for (auto& nbr : adj[src]) {
            if (!vis[nbr]) {
                dfs(nbr, adj, vis, cntV, cntE);
            }
        }
    }
  public:
    // TC : O(V + E)
    // SC : O(V)
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(v + 1, 0);
        int cntGoodComp = 0;
        for (int i = 1; i <= v; i++) {
            if (!visited[i]) {
                int cntVertex = 0;
                int cntEdges  = 0;
                
                dfs(i, adj, visited, cntVertex, cntEdges);
                
                if (cntVertex * (cntVertex - 1) == cntEdges)
                    cntGoodComp += 1;
            }
        }
        return cntGoodComp;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}
// } Driver Code Ends