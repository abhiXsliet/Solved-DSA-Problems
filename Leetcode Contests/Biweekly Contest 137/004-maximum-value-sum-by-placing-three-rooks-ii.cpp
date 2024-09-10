// https://leetcode.com/contest/biweekly-contest-137/problems/maximum-value-sum-by-placing-three-rooks-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define ll long long
    int m;
    int n;

    // TC : O((M*3)^2 * K) Where K is the average time of finding elements from the store array
    // SC : O(M * 3)
    ll way_1(vector<vector<int>>& board) {
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

    long long maximumValueSum(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();

        return way_1(board);    // weak approach but passed
    }
    
};