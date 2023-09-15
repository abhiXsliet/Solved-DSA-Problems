// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    typedef pair<int, int> P;
	public:
    // TC = O(E + (2 * log(E))) ~ O(E * log(E))
    // SC = O(V * V)
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({0, 0}); 
        
        vector<bool> vis(V, 0);
        
        int sum = 0;
        
        // O(E)
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop(); // O(log(E))
            
            int wt   = p.first;
            int node = p.second;
            
            if(vis[node] == 1) continue; // node is already visited
            
            vis[node] = 1; // mark node as visited
            sum += wt;
            
            for (auto& vec : adj[node]) {
                
                int neighbour = vec[0]; 
                int neigh_wt  = vec[1];
                
                if(vis[neighbour] == 0) 
                    pq.push({neigh_wt, neighbour}); // O(log(E))
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends