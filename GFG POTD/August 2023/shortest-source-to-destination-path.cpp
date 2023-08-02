// https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        
        int dx[] = {-1, 1, 0, 0}; // up, down, right, left
        int dy[] = {0, 0, 1, -1};
        
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            int d = node.first;
            int x = node.second.first;
            int y = node.second.second;
            
            if(x == X && y == Y) 
                return d;
            
            for(int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if(newx >= 0 && newy >= 0 && newx < N && newy < M && A[newx][newy] == 1) {
                    A[newx][newy] = 0;
                    q.push({d+1, {newx, newy}});
                }
            }
        }
        
        return -1;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends