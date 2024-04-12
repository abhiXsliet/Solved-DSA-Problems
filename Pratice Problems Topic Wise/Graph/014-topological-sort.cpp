// https://www.geeksforgeeks.org/problems/topological-sort/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    private:
    // TC : O(V + E)
    // SC : O(V) -> Recursive Depth
    void dfs(int src, vector<bool>& vis, vector<int> adj[], stack<int>& stk) {
        vis[src] = 1;
        for (int& nbr : adj[src]) {
            if (!vis[nbr]) {
                dfs(nbr, vis, adj, stk);
            }
        }
        stk.push(src);
    }
   
	// TC : O(V + E)
	// SC : O(V) -> Extra space used by visited array and stack 
    vector<int> solve_dfs(int V, vector<int> adj[]) {
        vector<bool> vis(V, 0);
	    stack<int> stk;
	    for (int i = 0; i < V; i++) {
	        if (!vis[i])
	            dfs(i, vis, adj, stk);
	    }
	    
	    vector<int> result;
	    while(!stk.empty()) {
	        result.push_back(stk.top());
	        stk.pop();
	    }
	    return result;
    }

	// TC : O(V + E)
	// SC : O(V) -> Extra space used by visited array and stack 
    vector<int> solve_bfs(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int& nbr : adj[i]) {
                indegree[nbr] ++;
            }
        }
        
        queue<int> q;
        // push node in queue whose indegree is 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) 
                q.push(i);
        }
        
        vector<int> result;
        while(!q.empty()) {
            int fNode = q.front();
            q.pop();
            
            for(int& nbr : adj[fNode]) {
                indegree[nbr] --;
                
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
            result.push_back(fNode);
        }
        return result;
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	   // return solve_dfs(V, adj); // DFS
	   
	   return solve_bfs(V, adj);    // BFS : Kahn's Algo
	}
};


//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends