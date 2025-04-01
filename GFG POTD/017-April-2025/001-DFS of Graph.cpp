// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    void DFS(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &result) {
        result.push_back(src);
        visited[src] = 1;
        for (int &nbr : adj[src]) {
            if (!visited[nbr]) {
                DFS(nbr, adj, visited, result);
            }
        }
    }
  public:
    // TC : O(V + E)
    // SC : O(V + E)
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> result;
        vector<bool> visited(n, 0);
        DFS(0, adj, visited, result);
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
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

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
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends