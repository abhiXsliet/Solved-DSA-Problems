// https://www.geeksforgeeks.org/problems/divisibility-tree1902/1



//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

    int ans=0;
    int dfs(vector<int>adj[], vector<int>&vis, int start){
        vis[start]=1;
        int cnt=0;
        
        for(auto it:adj[start]){
            if(!vis[it]){
                int res=dfs(adj, vis, it);
                if(res%2==0){
                    ans++;
                }
                else{
                    cnt+=res;
                }
            }
        }
        
        return cnt+1;
    }
    
    // TC : O(N)
    // SC : O(1)
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    vector<int>adj[n];
	    for(int i=0;i<edges.size();i++){
	        adj[edges[i][0]-1].push_back(edges[i][1]-1);
	        adj[edges[i][1]-1].push_back(edges[i][0]-1);
	    }
	    
	    vector<int>vis(n,0);
	    
	    dfs(adj, vis, 0);
	    
	    return ans;
	}
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends