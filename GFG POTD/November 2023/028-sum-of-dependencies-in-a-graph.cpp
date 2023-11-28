// https://www.geeksforgeeks.org/problems/sum-of-dependencies-in-a-graph5311/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    // TC = O(V + E)
    // SC = O(1)
    int solve_1(vector<int> adj[], int V) {
        int ans = 0;
        
        for (int u = 0; u < V; u++) {
            for (int& v : adj[u]) {
                ans ++;
            }
        }
        
        return ans;
    }
    
    // TC = O(V)
    // SC = O(1)
    int solve_2(vector<int> adj[], int V) {
        int ans = 0;
        for (int i = 0; i < V; i++) {
            ans += adj[i].size();
        }
        return ans;
    }
  public:
    int sumOfDependencies(vector<int> adj[], int V) {
        // return solve_1(adj, V);
        
        return solve_2(adj, V);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<int> v[N];
        for (int i = 0; i < M; i++) {
            cin >> x >> y;
            v[x].push_back(y);
        }
        Solution ob;
        cout << ob.sumOfDependencies(v, N) << "\n";
    }
}
// } Driver Code Ends