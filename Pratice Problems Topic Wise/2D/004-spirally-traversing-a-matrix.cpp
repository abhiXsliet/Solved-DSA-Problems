// https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1


//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    private:
    // TC = O(r*c)
    // SC = O(1)
    vector<int> solve_approach_1(vector<vector<int>>& arr, int r, int c) {
        int stRow = 0;
        int stCol = 0;
        int enRow = r - 1;
        int enCol = c - 1;
        
        int count = 0;
        int total = r * c;
        
        vector<int> result;
        
        while (count < total) {
            for (int i = stCol; count < total && i <= enCol; i++) {
                result.push_back(arr[stRow][i]);
                count++;
            }
            stRow++;
                
            for (int i = stRow; count < total && i <= enRow; i++) {
                result.push_back(arr[i][enCol]);
                count++;
            }
            enCol--;
                
            for (int i = enCol; count < total && i >= stCol; i--) {
                result.push_back(arr[enRow][i]);
                count++;
            }
            enRow--;
            
            for (int i = enRow; count < total && i >= stRow; i--) {
                result.push_back(arr[i][stCol]);
                count++;
            }
            stCol++;
        }
            
        return result;
    }
    
    // TC = O(r*c)
    // SC = O(1)
    vector<int> solve_approach_2(vector<vector<int>>& arr, int r, int c) {
        int stRow = 0;
        int stCol = 0;
        int enRow = r - 1;
        int enCol = c - 1;

        vector<int> result;
        
        while (stRow <= enRow && stCol <= enCol) {
            for (int i = stCol; i <= enCol; i++) 
                result.push_back(arr[stRow][i]);
            stRow++;
                
            for (int i = stRow; i <= enRow; i++) 
                result.push_back(arr[i][enCol]);
            enCol--;
             
            if (stRow <= enRow) {
                for (int i = enCol; i >= stCol; i--) 
                    result.push_back(arr[enRow][i]);
                enRow--;
            }   
            
            if (stCol <= enCol) {
                for (int i = enRow; i >= stRow; i--) 
                    result.push_back(arr[i][stCol]);
                stCol++;
            }
        }
            
        return result;
    }
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // return solve_approach_1(matrix, r, c);
        
        return solve_approach_2(matrix, r, c);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends