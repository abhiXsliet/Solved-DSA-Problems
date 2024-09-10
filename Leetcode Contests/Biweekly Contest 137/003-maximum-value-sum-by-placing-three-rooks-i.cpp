// https://leetcode.com/contest/biweekly-contest-137/problems/maximum-value-sum-by-placing-three-rooks-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m;
    int n;
    typedef long long ll;

    // TC : O((M*N)^3)
    ll brute(vector<vector<int>>& board) {
        ll ans = LLONG_MIN;

        // for Rook - I
        for (int a = 0; a < m; a ++) {
            for (int b = 0; b < n; b ++) {
                
                // for Rook - II
                for (int c = 0; c < m; c ++) {
                    if (c == a) continue;
                    for (int d = 0; d < n; d ++) {
                        if (d == b) continue;

                        // for Rook - III
                        for (int e = 0; e < m; e ++) {
                            if (e == a || e == c) continue;
                            for (int f = 0; f < n; f ++) {
                                if (f == b || f == d) continue;
                                
                                ll sum = board[a][b];
                                sum   += board[c][d];
                                sum   += board[e][f];
                                ans    = max(ans, sum);
                            }
                        }
                    }
                }

            }
        }

        return ans;
    }

    // TC : O((M*3)^3)
    // SC : O(M*3)
    ll better_1(vector<vector<int>>& board) {
        vector<vector<pair<int, int>>> newBoard(m, vector<pair<int, int>>(3));

        for (int i = 0; i < m; i ++) { 
            vector<pair<int, int>> temp;
            for (int j = 0; j < n; j ++) {
                temp.push_back({board[i][j], j});
            }
            sort(rbegin(temp), rend(temp));
            for (int j = 0; j < 3; j ++) {
                newBoard[i][j] = temp[j];
            }
        }

        ll ans = LLONG_MIN;

        // For Rook - I
        for (int a = 0; a < m; a ++) {
            for (int b = 0; b < 3; b ++) {

                // For Rook - II
                for (int c = 0; c < m; c ++) {
                    if (c == a) continue;   // skip same row
                    for (int d = 0; d < 3; d ++) {
                        if (newBoard[a][b].second == newBoard[c][d].second) continue;   // skip same column

                        // For Rook - III
                        for (int e = 0; e < m; e ++) {
                            if (e == a || e == c) continue; // skip same row
                            for (int f = 0; f < 3; f ++) {
                            if (newBoard[a][b].second == newBoard[e][f].second || 
                                newBoard[c][d].second == newBoard[e][f].second) continue;   // skip same column

                                ll sum = newBoard[a][b].first;
                                sum   += newBoard[c][d].first;
                                sum   += newBoard[e][f].first;
                                ans    = max(ans, sum);
                            }
                        }
                    }
                }
            }
        }
       
        return ans;
    }

    // TC : O((M*3)^3)
    // SC : O(M*3)
    ll better_2(vector<vector<int>>& board) {
        vector<vector<pair<int, int>>> newBoard(m, vector<pair<int, int>>(3));

        for (int i = 0; i < m; i ++) { 
            vector<pair<int, int>> temp;
            for (int j = 0; j < n; j ++) {
                temp.push_back({board[i][j], j});
            }
            sort(rbegin(temp), rend(temp));
            for (int j = 0; j < 3; j ++) {
                newBoard[i][j] = temp[j];
            }
        }

        ll ans = LLONG_MIN;
        
        for (int r1 = 0; r1 < m - 2; r1 ++) {           // Row-1 : For Rook - I
            for (int r2 = r1 + 1; r2 < m - 1; r2 ++) {  // Row-2 : For Rook - II
                for (int r3 = r2 + 1; r3 < m; r3 ++) {  // Row-3 : For Rook - III
                    
                    for (int c1 = 0; c1 < 3; c1 ++) {           // Try all top3 values of Row-1
                        for (int c2 = 0; c2 < 3; c2 ++) {       // Try all top3 values of Row-2
                            for (int c3 = 0; c3 < 3; c3 ++) {   // Try all top3 values of Row-3

                                if (newBoard[r1][c1].second == newBoard[r2][c2].second || 
                                    newBoard[r2][c2].second == newBoard[r3][c3].second ||
                                    newBoard[r1][c1].second == newBoard[r3][c3].second) 
                                        continue;
                                ll sum = newBoard[r1][c1].first;
                                sum   += newBoard[r2][c2].first;
                                sum   += newBoard[r3][c3].first;
                                ans    = max(ans, sum);
                            }
                        }
                    }
                }
            }
        }
       
        return ans;
    }

    // TC : O((M*3)^2 * K) Where K is the average time of finding elements from the store array
    // SC : O(M * 3)
    ll optimal(vector<vector<int>>& board) {
        vector<vector<pair<int, int>>> newBoard(m, vector<pair<int, int>>(3));
        vector<pair<int, pair<int, int>>> store; // {val, {i, j}}

        for (int i = 0; i < m; i ++) { 
            vector<pair<int, int>> temp;
            for (int j = 0; j < n; j ++) {
                temp.push_back({board[i][j], j});
            }
            sort(rbegin(temp), rend(temp));
            for (int j = 0; j < 3; j ++) {
                newBoard[i][j] = temp[j];
                store.push_back({temp[j].first, {i, temp[j].second}});
            }
        }        

        sort(rbegin(store), rend(store));

        ll ans = LLONG_MIN;
        
        for (int r1 = 0; r1 < m - 2; r1 ++) {      // Row-1 : For Rook - I
            for (int r2 = r1 + 1; r2 < m - 1; r2 ++) { // Row-2 : For Rook - II
                for (int c1 = 0; c1 < 3; c1 ++) {      // Try all top3 values of Row-1
                    for (int c2 = 0; c2 < 3; c2 ++) {  // Try all top3 values of Row-2

                        if (newBoard[r1][c1].second == newBoard[r2][c2].second) // skip same columns
                            continue;

                        for (int k = 0; k < 3*m; k ++) { // For Rook - III : check in store

                            int rowS     = store[k].second.first;   // i
                            int colS     = store[k].second.second;  // j

                            // If Not Same Row and Same Column : check in store
                            if (rowS != r1 && rowS  != r2) {
                                if (colS != newBoard[r1][c1].second && colS != newBoard[r2][c2].second) {
                                    ll sum = newBoard[r1][c1].first;
                                    sum   += newBoard[r2][c2].first;
                                    sum   += store[k].first;
                                    ans    = max(ans, sum);
                                    
                                    break;  // catch
                                }
                            }
                        }
                    }
                }
            }
        }
       
        return ans;
    }
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();

        // return brute(board);
        // return better_1(board);
        // return better_2(board); // concisely written 
        return optimal(board);
    }
};