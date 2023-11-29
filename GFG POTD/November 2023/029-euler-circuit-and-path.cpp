// https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    // TC = O(V + E)
    // SC = O(V) -> Max depth of recursive stack
    void DFS(int node, vector<bool>& visited, vector<int> adj[]) {
        visited[node] = true;
        
        for (auto it = adj[node].begin(); it != adj[node].end(); it++) {
            int neighbour = *it;
            
            if (visited[neighbour] == false) {
                DFS(neighbour, visited, adj);
            }
        }
    }
    
    // TC = O(V + E)
    // SC = O(V)
    bool isConnected(int V, vector<int> adj[]) {
        
        int nonZeroDegreeNode = -1;
        
        for (int i = 0; i < V; i++) {
            if (adj[i].size() > 0) {
                nonZeroDegreeNode = i;
                break;
            }
        }
        
        vector<bool> visited(V, false);
        
        // Start DFS from nonZeroDegreeNode
        DFS(nonZeroDegreeNode, visited, adj);
        
        // Check if all nonZeroDegreeNode are visited
        for (int i = 0; i < V; i++) {
            if (visited[i] == false && adj[i].size() > 0) {
                return false;
            }
        }
        
        return true;
    }
public:
	int isEulerCircuit(int V, vector<int>adj[]){
        // Step-1 : Check if all non-zero vertices are connected
        if (isConnected(V, adj) == false)
            return 0;
            
        // Step-2 : Count odd degree vertices/nodes
        int oddDegreeVertices = 0;
        
        for (int i = 0; i < V; i++) {
            if (adj[i].size() % 2 != 0) 
                oddDegreeVertices ++;
        }
        
        if (oddDegreeVertices > 2) 
            return 0;   // none
            
        if (oddDegreeVertices == 2)
            return 1;   // Eulerian Path
            
        return 2;       // Eulerian Circuit if oddDegreeVertices == 0
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends