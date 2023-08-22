// https://practice.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    // TC = O(n*n)
    // SC = O(n)
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int ans = 0;
        int maxi = 0;
        vector<int>rowSum(n, 0);
        vector<int>colSum(n, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                rowSum[i] += matrix[i][j];
                colSum[i] += matrix[j][i];
            }
            maxi = max(max(rowSum[i], colSum[i]), maxi);
        }
        
        for(int i = 0; i < n; i++) 
            ans += maxi - rowSum[i];
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends