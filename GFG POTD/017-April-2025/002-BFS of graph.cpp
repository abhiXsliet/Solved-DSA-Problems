// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    void BFS(int src, vector<vector<int>> &adj, vector<int> &result, vector<bool> &visited) {
        queue<int> q;
        q.push(src);
        visited[src] = 1;
        while (!q.empty()) {
            int fNode = q.front();
            q.pop();
            
            result.push_back(fNode);
            
            for (auto &nbr : adj[fNode]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = 1;
                }
            }   
        }
    }
  public:
    // TC : O(V + E)
    // SC : O(V + E)
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> result;
        vector<bool> visited(n, 0);
        BFS(0, adj, result, visited);
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        // Use vector of vectors instead of array of vectors.
        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.bfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends