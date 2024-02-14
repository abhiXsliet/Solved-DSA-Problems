// https://www.geeksforgeeks.org/problems/critical-connections/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    // TC : O(V + E)
    // SC : O(V) -> Recursive Depth
    void dfs(int node, int parent, int &timer, vector<int>& low, 
        vector<int>& disc, unordered_map<int, bool>& vis,
        vector<int> adj[], vector<vector<int>>& result ) {

        vis[node] = true;
        disc[node] = low[node] = timer++;
    
        for(auto neighbour: adj[node]) {
            if(neighbour == parent) {
                continue;
            }
            else if(!vis[neighbour]) {
                dfs(neighbour, node, timer, low, disc, vis, adj, result);
                low[node] = min(low[node], low[neighbour]);
    
                //check edge is a bridge?
                if(low[neighbour] > disc[node]) {
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(neighbour);
                    sort(begin(ans), end(ans));
                    result.push_back(ans);
                }
            }
            else {
                //Back Edge -> neighbour!=parent && visited[neighbour] == true
                low[node] = min(low[node], disc[neighbour]);
            }
        }
    }

public:
    // TC : O(V + E)
    // SC : O(V) -> Extra Space Used by low, discovery
	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
        //intialise all data structures
        vector<int> disc(v, -1);
        vector<int> low(v, -1);
        unordered_map<int, bool> visited;
    
        int parent = -1;
        int timer = 0;
    
        vector<vector<int>> result;
    
        //do dfs
        for(int i=0; i<v; i++) {
            if(!visited[i]) {
                dfs(i, parent, timer, low, disc, visited, adj, result);
            }
        }
        sort(begin(result), end(result));
        return result;
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
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends