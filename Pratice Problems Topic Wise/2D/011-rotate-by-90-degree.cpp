// https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1


// The task is to rotate it by 90 degrees in an anti-clockwise direction 
// without using any extra space.

//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    private:
    // TC = O(N * N)
    // SC = O(1)
    void rotate90_anti_clockwise_1(vector<vector<int>>& mat, int n) {
        // reverse the columns left to right
        for (int i = 0; i < n; i++) {
            reverse(begin(mat[i]), end(mat[i]));
        }
        
        // transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
    
    void rotate90_anti_clockwise_2(vector<vector<int>>& matrix, int n) {
        // transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
         
        // reverse the columns  
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n/2; j++) {
                swap(matrix[j][i], matrix[n-1-j][i]);
            }
        }
    }
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& matrix, int n) 
    { 
        // rotate90_anti_clockwise_1(matrix, n);
        
        rotate90_anti_clockwise_2(matrix, n);
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends