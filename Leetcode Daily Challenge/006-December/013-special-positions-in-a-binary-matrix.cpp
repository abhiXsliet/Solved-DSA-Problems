// https://leetcode.com/problems/special-positions-in-a-binary-matrix/




#include <bits/stdc++.h>
using namespace std; 

class Solution {
private:
    // TC = O(M*N*(M + N))
    // SC = O(1)
    int solve_brute(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    bool special = 1;
                    // check for rows
                    for (int row = 0; row < m; row++) {
                        if (row != i && mat[row][j] == 1) {
                            special = 0;
                            break;
                        }
                    }

                    // check for cols
                    for (int col = 0; col < n; col++) {
                        if (col != j && mat[i][col] == 1) {
                            special = 0;
                            break;
                        }
                    }

                    if (special) {
                        res++;
                    }
                }
            }
        }
        return res;
    }

    // TC = O(N * M)
    // SC = O(N) + O(M)
    int solve_optimal(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // store the no.s of 1s in a row
        vector<int> storeRow(m, 0);
        // store the no.s of 1s in a col
        vector<int> storeCol(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    storeRow[i]++;
                    storeCol[j]++;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && storeRow[i] == 1 && storeCol[j] == 1) {
                    res ++;
                }
            }
        }
        return res;
    }
public:
    int numSpecial(vector<vector<int>>& mat) {
        // return solve_brute(mat);

        return solve_optimal(mat);
    }
};