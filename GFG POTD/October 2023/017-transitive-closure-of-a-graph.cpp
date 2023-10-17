// https://practice.geeksforgeeks.org/problems/transitive-closure-of-a-graph0930/1


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
private:
    void dfs(int i, int j, vector<vector<int>>& adj, vector<vector<int>>& ans) {
        ans[i][j] = 1;
        for (int k = 0; k < adj[j].size(); k++) {
            if (adj[j][k] == 1 && ans[i][k] == 0) {
                dfs(i, k, adj, ans);
            }
        }
    }
    
    // TC = O(N^2)
    vector<vector<int>> solve_approach_dfs(int n, vector<vector<int>> graph) {
        
        vector<vector<int>> adj(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1 && i != j) {
                    adj[i][j] = 1;
                }
            }
        }
        
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dfs(i, i, adj, ans);
        }
        
        return ans;
    }
    
    // TC = O(N^3)
    vector<vector<int>> approach_2_floyd_warshall_algo(int n, vector<vector<int>> grid) {
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) grid[i][j] = 1;
                    
                    if (grid[i][j] == 0) {
                        if (grid[i][k] == 1 && grid[k][j] == 1)
                            grid[i][j] = 1;
                    }
                }
            }
        }
        
        return grid;
    }
public:
    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> graph)
    {
        // return approach_1_dfs(n, graph);
        
        
        return approach_2_floyd_warshall_algo(n, graph);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends