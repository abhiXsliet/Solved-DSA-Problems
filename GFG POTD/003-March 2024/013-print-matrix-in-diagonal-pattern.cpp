// https://www.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

/*You are required to complete this method */

class Solution{ 
  private:
    // TC : O(N*M) Where N = mat.size() (rows) & M = mat[0].size() (cols)
    // SC : O(N*M)
    vector<int> solve_1(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, vector<int>> mpp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mpp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> result;
        bool flip = 1;
        for (auto& it : mpp) {
            vector<int>temp;
            for (int& num : it.second) {
                if (flip == 0) {
                    result.push_back(num);
                }
                else temp.push_back(num);
            }
            if (flip == 1) {
                reverse(begin(temp), end(temp));
                for (auto& num : temp) {
                    result.push_back(num);
                }
                temp = {};
            }
            
            // can be done in two lines
            // if (flip) reverse(begin(it.second), end(it.second));
            // for (auto& num : it.second)  result.push_back(num);
            
            flip = !flip;
        }
        return result;
    }
    
    // TC : O(N*M) Where N = mat.size() (rows) & M = mat[0].size() (cols)
    // SC : O(1)
    vector<int> solve_2(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int flip = 1;
        int row  = 0;
        int col  = 0;
        int i    = 0;
        vector<int> result(n*m, 0);
        
        while (i < n*m) {
            if (flip) { // going upward
                while (row > 0 && col < n - 1) {
                    result[i++] = mat[row][col];
                    row --,col ++;
                }
                result[i++] = mat[row][col];
                if (col == n - 1) row ++;
                else col ++;
            }
            else {  // going downward
                while (row < m - 1 && col > 0) {
                    result[i++] = mat[row][col];
                    row ++, col --;
                }
                result[i++] = mat[row][col];
                if (row == m - 1) col ++;
                else row ++;
            }
            flip = !flip;
        }
        return result;
    }
    
    // TC : O(N*M) Where N = mat.size() (rows) & M = mat[0].size() (cols)
    // SC : O(1)
    vector<int> solve_3(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int flip = 1;
        int row  = 0;
        int col  = 0;
        int i    = 0;
        vector<int> result(n*m, 0);
        
        while (i < n*m) {
            if (flip) { // going upward
                while (row >= 0 && col < n) {
                    result[i++] = mat[row][col];
                    if (col == n - 1) {
                        row ++; break;
                    }
                    else if (row == 0) {
                        col ++; break;
                    }
                    row --,col ++;
                }
            }
            else {  // going downward
                while (row < m && col >= 0) {
                    result[i++] = mat[row][col];
                    if (row == m - 1) {
                        col ++; break;
                    }
                    else if (col == 0) {
                        row ++; break;
                    }
                    row ++, col --;
                }
            }
            flip = !flip;
        }
        return result;
    }
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat) {
        //  return solve_1(mat);
        
        // return solve_2(mat);
        
        return solve_3(mat);
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends