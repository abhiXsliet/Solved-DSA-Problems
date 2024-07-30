// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1




//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function template for C++

class Solution {
    private:
    bool isSafe(int i, int j, int n){
        return i >= 0 && i < n && j >= 0 && j < n; 
    }
     
    void solve(int i, int j, vector<vector<int>>& m, int n, string& path, vector<string>& ans) {
        if (!isSafe(i, j, n) || m[i][j] == 0) 
            return;
            
        if(i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }
        
        m[i][j] = 0;
        
        path.push_back('D');
        solve(i + 1, j, m, n, path, ans);
        path.pop_back();
        
        path.push_back('L');
        solve(i, j - 1, m, n, path, ans);
        path.pop_back();
        
        path.push_back('R');
        solve(i, j + 1, m, n, path, ans);
        path.pop_back();
        
        path.push_back('U');
        solve(i - 1, j, m, n, path, ans);
        path.pop_back();
        
        m[i][j] = 1;
    }
  public:
    // TC : O(3^(n^2))
    // SC : O(L * X) - L = Length of path, X = number of paths
    vector<string> findPath(vector<vector<int>>& m) {
        int n = m.size();
        vector<string> ans;
        string path;
        
        solve(0, 0, m, n, path, ans);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends