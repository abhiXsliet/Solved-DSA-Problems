// https://leetcode.com/problems/painting-a-grid-with-three-different-colors/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int M = 1e9 + 7;
    vector<string> colStates;
    vector<vector<int>> t;

    void generateColStates(string currCol, char prevChar, int remRows) {
        if (remRows == 0) {
            colStates.push_back(currCol);
            return;
        }

        for (char ch : {'R', 'G', 'B'}) {
            if (ch == prevChar) continue;
            generateColStates(currCol + ch, ch, remRows - 1);
        }
    }

    int solve(int remCols, int prevColIdx, int m) {
        if (remCols == 0) return 1;

        if (t[remCols][prevColIdx] != -1)
            return t[remCols][prevColIdx];

        int totalWays = 0;
        string prevCol = colStates[prevColIdx];

        for (int nextColIdx = 0; nextColIdx < colStates.size(); nextColIdx ++) {
            string nextCol = colStates[nextColIdx];
            bool isValid = true;

            for (int r = 0; r < m; r ++) {
                if (prevCol[r] == nextCol[r]) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                totalWays = (totalWays + solve(remCols - 1, nextColIdx, m)) % M;
            }
        }

        return t[remCols][prevColIdx] = totalWays;
    }
public:
    // TC : O(n * S * S * m), where S = total states i.e. 3 * 2^m-1
    // SC : O((n * S) + (S * m)) where n * S is because of memoization array t, and S * m is for storing columnStates
    int colorTheGrid(int m, int n) {
        generateColStates("", '#', m); 

        int cntColPattern = colStates.size();
        t.assign(n, vector<int>(cntColPattern, -1));

        int result = 0;
        for (int i = 0; i < cntColPattern; i ++) {
            result = (result + solve(n - 1, i, m)) % M;
        }   
        return result;
    }
};