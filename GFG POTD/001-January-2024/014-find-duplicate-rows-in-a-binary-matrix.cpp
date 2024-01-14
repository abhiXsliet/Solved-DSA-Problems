// https://www.geeksforgeeks.org/problems/find-duplicate-rows-in-a-binary-matrix/1



//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{   
    private:
    // TC : O(M^2 * N)
    // SC : O(M * N)
    vector<int> solve_brute(vector<vector<int>>& matrix, int m, int n) {
        vector<vector<int>> store = matrix;
        vector<int> result;
        
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if (store[i] == matrix[j]) { //  comparison takes (O(N)) time
                    result.push_back(j);
                    break;
                }
            }
        }
        sort(begin(result), end(result));
        return result;
    }
    
    // TC (Averge): O(M * N)
    // TC (Worst): O(M * (M + N)) since Map has average time of O(1) & O(M) when hash collision occurs
    // SC : O(M * N)
    vector<int> solve_better(vector<vector<int>>& matrix, int m, int n) {
        vector<int> result;
        unordered_map<string, int> rowMap;
        
        for (int i = 0; i < m; i++) {
            string row;
            for (int j = 0; j < n; j++) {
                row += to_string(matrix[i][j]) + ", ";
            }
            
            if (rowMap.find(row) != rowMap.end()) {
                result.push_back(i);
            }
            else {
                rowMap[row] = i;
            }
        }
        return result;
    }
    
    // 'find/insert' opr in a set of vectors is (O(log k)), where k is the no of elements in the set. 
    // However, since the elements are vectors, the comparison of vectors takes (O(n)) time,
    
    // TC : O(M * N(log(M))) 
    // SC : O(M)
    vector<int> solve_optimal_2(vector<vector<int>>& matrix, int m, int n) {
        set<vector<int>> stRow;
        vector<int> result;
        for (int i = 0; i < m; i++) {
            if (stRow.find(matrix[i]) != stRow.end()) {
                result.push_back(i);
            }
            else {
                stRow.insert(matrix[i]);
            }
        }
        return result;
    }
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // return solve_brute(matrix, M, N);
        
        // return solve_better(matrix, M, N);
        
        return solve_optimal_2(matrix, M, N);
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends