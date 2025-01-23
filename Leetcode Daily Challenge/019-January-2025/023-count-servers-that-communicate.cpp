// https://leetcode.com/problems/count-servers-that-communicate/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O((M * N) * (M + N))
    // SC : O(1)
    int approach_1(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int communicableServers = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j]) {
                    bool isCommunicable = false;
                    // check in row if there's a communicable server
                    for (int r = 0; r < m; r ++) {
                        if (grid[r][j] && r != i) {
                            isCommunicable = true;
                            break;
                        }
                    }
                    if (isCommunicable) communicableServers ++;
                    else { // check in col if there's a communicable server
                        for (int c = 0; c < n; c ++) {
                            if (grid[i][c] && j != c) {
                                communicableServers ++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return communicableServers;
    }

    // TC : O(M * N)
    // SC : O(M + N)
    int approach_2(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rowServers(m, 0);   // stores count of servers of each row
        vector<int> colServers(n, 0);   // stores count of servers of each col

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j]) {
                    rowServers[i] ++;
                    colServers[j] ++;
                }
            }
        }

        int communicableServers = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] && (rowServers[i] > 1 || colServers[j] > 1)) {
                    communicableServers += 1;
                }
            }
        }
        return communicableServers;
    }

    // TC : O(M * N)
    // SC : O(M + N)
    int approach_3(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> colServers(n, 0);    // stores count of servers of each col
        vector<int> aloneServersRow(m, -1);  // stores count of alone servers in each row
        
        int communicableServers = 0;
        for (int i = 0; i < m; i ++) {
            int eachRowServers = 0;
            for (int j = 0; j < n; j ++) {
                if (grid[i][j]) {
                    eachRowServers += 1;
                    aloneServersRow[i] = j; // update alone server and store jth col
                    colServers[j] += 1;
                }
            }
            if (eachRowServers > 1) {
                communicableServers += eachRowServers;
                aloneServersRow[i] = -1;
            }
        }

        for (int i = 0; i < m; i ++) {
            if (aloneServersRow[i] != -1) { // if a alone server in ith row then check its corresponding col 
                int j = aloneServersRow[i];
                if (colServers[j] > 1) {
                    communicableServers += 1;
                }
            }
        }
        return communicableServers;
    }
public:
    int countServers(vector<vector<int>>& grid) {
       // return approach_1(grid);
       // return approach_2(grid);
       return approach_3(grid);     // No optimization from approach_2, just different logic
                                    // DSU : PENDING ?? 
    }
};