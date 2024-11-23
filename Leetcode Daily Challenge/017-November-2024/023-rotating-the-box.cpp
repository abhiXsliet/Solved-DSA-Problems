// https://leetcode.com/problems/rotating-the-box/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M * N * N)
    // SC : O(1)
    vector<vector<char>> approach_1(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();

        vector<vector<char>> result(n, vector<char>(m));

        // Rotating 90 deg. clockwise
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                result[i][j] = box[j][i];
            }
        }
        for (vector<char>& row : result) {
            reverse(begin(row), end(row));
        }

        // Applying gravity
        for (int j = 0; j < m; j ++) {
            for (int i = n - 1; i >= 0; i --) {
                if (result[i][j] == '.') {
                    int stoneRow = -1;
                    for (int k = i - 1; k >= 0; k --) {
                        if(result[k][j] == '*') {
                            break;
                        } else if(result[k][j] == '#') {
                            stoneRow = k;
                            break;
                        }
                    }
                    if (stoneRow != -1) {
                        result[i][j] = '#';
                        result[stoneRow][j] = '.';
                    }
                }
            }
        }

        return result;
    }

    // TC : O(M * N)
    // SC : O(1)
    vector<vector<char>> approach_2(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();

        vector<vector<char>> result(n, vector<char>(m));

        // Rotating 90 deg. clockwise
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                result[i][j] = box[j][i];
            }
        }
        for (vector<char>& row : result) {
            reverse(begin(row), end(row));
        }

        // Applying Gravity
        for (int j = 0; j < m; j ++) {
            int emptySpaceRow = n - 1;
            for (int i = n - 1; i >= 0; i --) {
                if (result[i][j] == '*') {
                    emptySpaceRow = i - 1;
                    continue;
                } 
                if (result[i][j] == '#') {
                    result[i][j] = '.';
                    result[emptySpaceRow][j] = '#';
                    emptySpaceRow --;
                }
            }
        }

        return result;
    }
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // return approach_1(box); // SIMULATION   

        return approach_2(box);
    }
};