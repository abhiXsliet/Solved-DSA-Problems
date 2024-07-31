// https://www.geeksforgeeks.org/problems/maximum-connected-group/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    class disjointSet {
        public:
        vector<int> rank, parent, size;
        disjointSet(int n) {
            parent.resize(n);
            size.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
    
        int findUPar(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findUPar(parent[node]);
        }
    
        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        vector<vector<int>> ind_map(n,vector<int>(n,0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ind_map[i][j] = cnt;
                cnt++;
            }
        }
        disjointSet ds(n*n);
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int nrow = i+drow[k];
                        int ncol = j+dcol[k];
                        if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==1){
                            ds.unionBySize(ind_map[i][j],ind_map[nrow][ncol]);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n*n;i++){
            ans = max(ans,ds.size[ds.findUPar(i)]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int temp = 0;
                    vector<int> upar(4,-1);
                    for(int k=0;k<4;k++){
                        int nrow = i+drow[k];
                        int ncol = j+dcol[k];
                        int flag = 1;
                        if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==1){
                            int u_par = ds.findUPar(ind_map[nrow][ncol]);
                            for(int l=0;l<4;l++){
                                if(u_par == upar[l]) flag=0;
                            }
                            if(flag==1) temp+=ds.size[u_par];
                            upar[k] = u_par;
                        }
                    }
                    ans = max(ans,temp+1);
                }
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends