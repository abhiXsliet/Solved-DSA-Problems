// https://www.geeksforgeeks.org/problems/circle-of-strings4530/1



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
    void DFS(int node, vector<bool>& visited, vector<int> adj[]) {
        visited[node] = true;
        
        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                DFS(neighbour, visited, adj);
            }
        }
    }
    
    bool isConnected(int V, vector<int> adj[]) {
        int nonZeroDegreeNode = -1;
        
        for (int i = 0; i < V; i++) {
            if (adj[i].size() > 0) {
                nonZeroDegreeNode = i;
                break;
            }
        }
        
        if (nonZeroDegreeNode == -1) {
            // All nodes have degree 0, hence it's trivially connected
            return true;
        }
        
        vector<bool> visited(V, false);
        
        // Start DFS from nonZeroDegreeNode
        DFS(nonZeroDegreeNode, visited, adj);
        
        // Check if all nodes with non-zero degree are visited
        for (int i = 0; i < V; i++) {
            if (!visited[i] && adj[i].size() > 0) {
                return false;
            }
        }
        
        return true;
    }
    
  public:
    // TC : O(N)
    // SC : O(N)
    int isCircle(vector<string>& arr) {
        int n = arr.size();
        vector<int> adj[26];  // Adjacency list for 26 letters
        
        vector<int> inDegree(26, 0), outDegree(26, 0);
        
        // Build the adjacency list and calculate in/out degrees
        for (int i = 0; i < n; i ++) {
            int u = arr[i][0] - 'a';              // Start character
            int v = arr[i].back() - 'a';          // End character
            
            adj[u].push_back(v);  // Directed edge u -> v
            outDegree[u] ++;
            inDegree[v] ++;
        }
        
        // Step 1: Check if the graph is strongly connected
        if (!isConnected(26, adj)) 
            return false;
        
        // Step 2: Check in-degree == out-degree for all vertices
        for (int i = 0; i < 26; i++) {
            if (inDegree[i] != outDegree[i]) {
                return false;
            }
        }
        
        return true;  // The graph has an Eulerian circuit
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends