// https://www.geeksforgeeks.org/problems/detect-cycle-using-dsu/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    // TC = O(N)
    // SC = O(1)
    void makeSet(vector<int>& parent, vector<int>& rank, int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }    
    }
    
    // TC = O(α(n)) where α(n) = inverse Ackermann function. 
    // This function has a very slow growth rate, and for all practical purposes, it can be considered a constant. Hence, the time complexity is effectively constant.
    // SC = O(1)
    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node)
            return node;
            
        return parent[node] = findParent(parent, parent[node]);
    }

    // TC = O(α(n)) where α(n) = inverse Ackermann function. 
    // This function has a very slow growth rate, and for all practical purposes, it can be considered a constant. Hence, the time complexity is effectively constant.
    // SC = O(1)
    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);
        
        if (rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if (rank[u] > rank[v]) {
            parent[v] = u;
        }
        else {
            parent[u] = v;
            rank[v]++;
        }
    }
    public:
    // TC = O(V + E)
    // SC = O(V)
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[]) {
        vector<int> parent(V);
        vector<int> rank(V);
        
        makeSet(parent, rank, V);
        
        for (int u = 0; u < V; u++) {
            
            for (int &v : adj[u]) {
                
                if (u < v) {
                    
                    int parent_u = findParent(parent, u);
                    int parent_v = findParent(parent, v);
                    
                    if (parent_u == parent_v) 
                        return true;
                    
                    unionSet(u, v, parent, rank);
                }
            }
        }
        
        return false;
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends