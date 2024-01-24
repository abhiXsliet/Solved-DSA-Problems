// https://www.geeksforgeeks.org/problems/is-it-a-tree/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  private:
    // TC : O(n), where n is the number of nodes in the graph
    // SC : O(n), where n is the number of nodes in the graph
    // DFS function to check for a cycle in the graph
    bool DFS(int node, int parent, vector<bool>& visited, unordered_map<int, vector<int>>& adj) {
        visited[node] = true;  // Mark the current node as visited
        
        // Loop through all adjacent nodes
        for (auto it = adj[node].begin(); it != adj[node].end(); it++) {
            int neighbour = *it;
            
            // If the adjacent node is not visited, recursively call DFS for that node
            if (!visited[neighbour]) {
                if (DFS(neighbour, node, visited, adj)) {
                    return true;
                }
            } 
            // If an adjacent node is visited and it is not the parent of the current node, then there is a cycle
            else if (neighbour != parent) {
                return true;
            }
        }
        // If no cycle is found, return false
        return false;  
    }
    
    // TC : O(n), where n is the number of nodes in the graph
    // SC : O(n), where n is the number of nodes in the graph
    // Function to check if the graph is connected
    bool isConnected(int V, unordered_map<int, vector<int>>& adj) {
        
        int nonZeroDegreeNode = -1;
        
        // Find a node with a non-zero degree
        for (int i = 0; i < V; i++) {
            if (adj[i].size() > 0) {
                nonZeroDegreeNode = i;
                break;
            }
        }
        
        // If there are no edges in the graph
        if (nonZeroDegreeNode == -1) {
            // If there is only one node, it's a tree
            if (V == 1) {
                return true;
            }
            // Otherwise, it's not a tree
            else {
                return false;
            }
        }
        
        // Initialize visited array
        vector<bool> visited(V, false);  
        
        // Start DFS from nonZeroDegreeNode
        if (DFS(nonZeroDegreeNode, -1, visited, adj)) {
            // If DFS returns true, then a cycle is detected, so return false
            return false;  
        }
        
        // Check if all nonZeroDegreeNode are visited
        for (int i = 0; i < V; i++) {
            if (visited[i] == false && adj[i].size() > 0) {
                // If any node is not visited, return false
                return false;  
            }
        }
        // If all nodes are visited and no cycle is detected, return true
        return true;  
    }
    
  public:
    // TC :  O(n + m), where n is the number of nodes and m is the number of edges in the graph
    // SC : O(n + m), space required for the adjacency list (which is proportional to the number of edges and vertices)
    int isTree(int n, int m, vector<vector<int>> &edges) {
        // If the number of edges is not one less than the number of nodes, it's not a tree
        if (m != n - 1) return 0;  
        
        // Create an adjacency list
        unordered_map<int, vector<int>> adjacency;  
        for (auto& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adjacency[u].push_back(v);
            adjacency[v].push_back(u);
        }
        
        // If the graph is not connected, return 0
        if (isConnected(n, adjacency) == false) return 0;  
        
        // If the graph is connected and no cycle is detected, return 1
        return 1; 
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends