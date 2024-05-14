// https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    // TC : O(Rows * Columns)
    // SC : O(Rows * Columns)
    int MinimumEffort(int n, int m, vector<vector<int>> &heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>>dist(n, vector<int>(m,INT_MAX));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            int step=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            
            pq.pop();
            
            if(row==n-1 && col==m-1){
                return step;
            }
            
            int nrow, ncol;
            
            nrow=row-1; ncol=col;
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                int val=max(step, abs(heights[nrow][ncol]-heights[row][col]));
                if(val<dist[nrow][ncol]){
                    dist[nrow][ncol]=val;
                    pq.push({val, {nrow,ncol}});
                }
            }
            nrow=row+1; ncol=col;
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                int val=max(step, abs(heights[nrow][ncol]-heights[row][col]));
                if(val<dist[nrow][ncol]){
                    dist[nrow][ncol]=val;
                    pq.push({val, {nrow,ncol}});
                }
            }
            nrow=row; ncol=col-1;
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                int val=max(step, abs(heights[nrow][ncol]-heights[row][col]));
                if(val<dist[nrow][ncol]){
                    dist[nrow][ncol]=val;
                    pq.push({val, {nrow,ncol}});
                }
            }
            nrow=row; ncol=col+1;
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                int val=max(step, abs(heights[nrow][ncol]-heights[row][col]));
                if(val<dist[nrow][ncol]){
                    dist[nrow][ncol]=val;
                    pq.push({val, {nrow,ncol}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}
// } Driver Code Ends