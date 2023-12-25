// https://www.geeksforgeeks.org/problems/determinant-of-a-matrix-1587115620/1




//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    private:
    int solve_way_1(vector<vector<int>>& matrix, int n) {
        if (n == 1) return matrix[0][0];
        if (n == 2) return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
        
        int ans  = 0;
        int sign = 1;   
        for (int i = 0; i < n; i++) {
            vector<vector<int>> temp(n-1, vector<int>(n-1));
            int row = 0;
            for (int col = 0; col < n; col++) {
                if (col == i) continue;
            
                for (int k = 1; k < n; k++) {
                    temp[k - 1][row] = matrix[k][col];
                }
                row++;
            }
            ans += sign * matrix[0][i] * solve_way_1(temp, n - 1);
            sign = -sign;
        }
        
        return ans;
    }
    
    void cofactor(vector<vector<int>>& matrix, vector<vector<int>>& temp, int R, int C, int n) {
        int i = 0;
        int j = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (row != R && col != C) {
                    temp[i][j] = matrix[row][col];
                    j++;
                    
                    if (j == n - 1) {
                        j = 0;
                        i ++;
                    }
                }
            }
        }
    }
    
    int solve_way_2(vector<vector<int>>& matrix, int n) {
        int ans = 0;
        if (n == 1) return matrix[0][0];
        
        vector<vector<int>> temp(n, vector<int>(n));
        
        int sign = 1;
        for (int i = 0; i < n; i++) {
            cofactor(matrix, temp, 0, i, n);
            ans += sign * matrix[0][i] * solve_way_2(temp, n - 1);
            sign *= -1;
        }
        
        return ans;
    }
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
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
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends