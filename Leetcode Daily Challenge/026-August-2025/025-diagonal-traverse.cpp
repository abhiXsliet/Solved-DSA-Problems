// https://leetcode.com/problems/diagonal-traverse/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:    
    // TC : O(M*N*log(M*N))
    // SC : O(M*N)
    vector<int> approach_1(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        map<int, vector<int>> mpp;
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                mpp[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> result;

        for (auto &it : mpp) {
            if (it.first % 2 == 0) {
                reverse(begin(it.second), end(it.second));
            }
            for (int &val : it.second) {
                result.push_back(val);
            }
        }

        return result;
    }

    // TC : O(M*N)
    // SC : O(1)
    vector<int> approach_2(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        vector<int> result;
        result.reserve(m*n);

        int i = 0, j = 0;
        bool flip = true;
        
        while (i < m && j < n) {
            if (flip) {
                while (i >= 0 && j < n) {
                    result.push_back(mat[i][j]);
                    i --, j ++;
                }
                if (j == n) {   // reached out of columns
                    i += 2;     
                    j -= 1;
                } else {
                    i += 1;
                }
            } else {
                while (i < m && j >= 0) {
                    result.push_back(mat[i][j]);
                    i ++, j --;
                }
                if (i == m) {   // reached out of rows
                    j += 2;
                    i -= 1;
                } else {
                    j += 1;
                }
            }

            flip = !flip;
        }

        return result;
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // return approach_1(mat);
        return approach_2(mat);
    }
};