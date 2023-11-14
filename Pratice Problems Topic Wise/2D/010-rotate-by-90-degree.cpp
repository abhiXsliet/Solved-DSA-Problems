// https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1


//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


// } Driver Code Ends
//User function template for C++
void solve_optimal_1(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // reverse the rows
    for (int i = 0; i < n; i++) {
        reverse(begin(matrix[i]), end(matrix[i]));
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

// TC = O(N * N)
// SC = O(1)
void solve_optimal_2(vector<vector<int>>& matrix) {
    int n = matrix.size();
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
     
    // reverse the columns
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n/2; j++) {
            swap(matrix[i][j], matrix[n-1-j][i]);
        }
    }
    
}
/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{
    solve_optimal_1(matrix);
    
    // solve_optimal_2(matrix);
}


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}


// } Driver Code Ends