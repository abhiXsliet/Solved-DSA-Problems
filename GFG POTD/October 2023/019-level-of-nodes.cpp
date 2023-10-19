// https://practice.geeksforgeeks.org/problems/level-of-nodes-1587115620/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    int vis[V] = {0};
	    queue<pair<int, int>> que;
	    que.push({0, 0}); // {node, level}
	    vis[0] = 1;
	    
	    while(!que.empty()) {
	        int node  = que.front().first;
	        int level = que.front().second;
	        que.pop();
	        
	        if (node == X) return level;
	        
	        for (auto neigh : adj[node]) {
	            if (!vis[neigh]) {
	                que.push({neigh, level+1});
	                vis[neigh] = 1;
	            }
	        }
	    }
	    
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends