// https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
private:
    typedef long long ll;
    int M = 1e9 + 7;
    int t[101][101][101];
    
    // TC : O(N^2 * K)
    // SC : O(N^2 * K)
    ll solve_mem(vector<vector<int>>& arr, int n, int k, int i, int j) {
        if (i == n - 1 && j == n - 1) {
            if (k == arr[i][j]) return 1;
            else return 0;
        }
        
        if (i >= n || j >= n || k < 0) return 0;
        
        if (t[i][j][k] != -1) return t[i][j][k];
        
        ll down  = solve_mem(arr, n, k - arr[i][j], i + 1, j);
        ll right = solve_mem(arr, n, k - arr[i][j], i, j + 1);
        
        return t[i][j][k] = (right + down) % M; 
    }
public:
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        memset(t, -1, sizeof(t));
        return solve_mem(arr, n, k, 0, 0);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends