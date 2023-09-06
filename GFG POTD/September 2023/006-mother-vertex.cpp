// https://practice.geeksforgeeks.org/problems/mother-vertex/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    private:
    void dfs(int node, vector<bool>& vis, vector<int> adj[]) {
        vis[node] = 1;
        for (auto& neighbour : adj[node]) {
            if (!vis[neighbour]) {
                dfs(neighbour, vis, adj);
            }
        }
    }
    
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool> vis(V);
	    int motherVer = -1;
	    
	    for (int i = 0; i < V; i++) {
	        if (!vis[i]) {
	            dfs(i, vis, adj);
	            motherVer = i;
	        }
	    }
	    
	    // reset visited array to false
	    fill(vis.begin(), vis.end(), 0);
	    // vis.assign(V, 0);
	    
	    // check if the mother vertex covers all the nodes
	    dfs(motherVer, vis, adj);
	    // check if any vertex remains unvisited
	    for (int i = 0; i < V; i++) {
	        if (!vis[i]) 
	            return -1;
	    }
	    
	    return motherVer;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends