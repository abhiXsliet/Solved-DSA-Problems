// https://www.geeksforgeeks.org/problems/sum-of-upper-and-lower-triangles-1587115621/1


//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
// } Driver Code Ends

class Solution
{   
    private:
    int getUpperSum (const vector<vector<int>>& matrix, int n, int row, int col) {
        int upperSum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                upperSum += matrix[i][j];
            }
        }
        return upperSum;
    }
    
    int getLowerSum (const vector<vector<int>>& matrix, int n, int row, int col) {
        int lowerSum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                lowerSum += matrix[i][j];
            }
        }
        return lowerSum;
    }
    
    vector<int> solve_way_1(const vector<vector<int>>& matrix, int n) {
        vector<int> result;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int upperSum = getUpperSum(matrix, n, row, col);
        result.push_back(upperSum);
        
        int lowerSum = getLowerSum(matrix, n, row, col);
        result.push_back(lowerSum);
        
        return result;
    }
    
    vector<int> solve_way_2(const vector<vector<int>>& matrix, int n) {
        int upperSum = 0, lowerSum = 0;
        
        vector<int> result;
        int row = matrix.size();
        int col = matrix[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j >= i) upperSum += matrix[i][j];
                if (j <= i) lowerSum += matrix[i][j];
            }
        }
        
        result.push_back(upperSum);
        result.push_back(lowerSum);
        
        return result;
    }
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        // return solve_way_1(matrix, n);
        
        return solve_way_2(matrix, n);
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
        vector<int> result = ob.sumTriangles(matrix,n);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends