// https://www.geeksforgeeks.org/problems/vertex-cover/1



//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
        // TC : O(N * 2^N * M) Where N, M = No. of edges and vertices respectively
        // SC : O(1)
        int solve_approach_1(int n, vector<pair<int, int>>& edges) {
            int ans = 20; // Initialize the answer to a large value
    
            // Iterate over all subsets of vertices
            for (int i = 0; i < (1 << n); i++) {
                // Initialize m to the number of edges
                int m = edges.size(); 
                
                // Iterate over all edges
                for (auto& edge : edges) {
                    int x = edge.first - 1; // Decrement x by one
                    int y = edge.second - 1;// Decrement y by one
                    
                    // If either endpoint is in the current subset, decrement m
                    if (((i >> x) & 1) || ((i >> y) & 1)) 
                        m--;
                    else break; // If neither endpoint is in the subset, break the loop
                }
                
                // If all edges have been covered, update the answer
                if (m == 0)
                // __builtin_popcount(i) returns the number of 1's in the binary representation of i
                    ans = min(ans, __builtin_popcount(i)); 
            }
            // Return the minimum number of vertices that cover all edges
            return ans; 
        }
        
        int next(int x){
            unsigned smallest, ripple, new_smallest, ones;
    
            if (x == 0) return 0;
            smallest     = (x & -x);
            ripple       = x + smallest;
            new_smallest = (ripple & -ripple);
            ones         = ((new_smallest/smallest) >> 1) - 1;
            return ripple | ones;
        }
        
        // TC : O(2^n * m) where n & m = no. of vertices & edges respectively
        // SC : O(1)
        bool check(int bits, int n, vector<pair<int, int>> &edges) {
            int cur = (1 << bits) - 1;
            
            while(cur < (1 << n)){
                int m = edges.size();
                
                for(auto edge : edges){
                    int x, y;
                    tie(x, y) = edge;
                    --x; --y;
                    
                    if(((cur >> x) & 1) or ((cur >> y) & 1))
                        --m;
                }
                
                if(m == 0)
                    return true;
                        
                cur = next(cur);
            }
            return false;
        }

        // TC : O(n * 2^n * mlog(n)) Where n, m = no. of vertices and edges respectively
        // SC : O(1)
        int solve_approach_2(int n, vector<pair<int, int>>& edges) {
            int low = 0;
            int high = n;
            
            while(low < high - 1){
                int mid = low + (high - low) / 2;
                
                if(check(mid, n, edges))
                    high = mid;
                else
                    low = mid;
            }
            
            return high;
        }
    public:
        int vertexCover(int n, vector<pair<int, int>> &edges) {
            // return solve_approach_1(n, edges);
            
            return solve_approach_2(n, edges);
        }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends