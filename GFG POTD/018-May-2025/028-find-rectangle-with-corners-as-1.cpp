// https://www.geeksforgeeks.org/problems/find-rectangle-with-corners-as-1--141631/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(M^2 * N^2)
    // SC : O(1)
    bool brute(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mat[i][j] == 1) {
                    // other (i2, j2) where rectangle might form
                    for (int i2 = i + 1; i2 < m; i2 ++) {
                        for (int j2 = j + 1; j2 < n; j2 ++) {
                            if (mat[i][j2] == 1 && mat[i2][j] == 1 && mat[i2][j2] == 1) {
                                return true;
                            } 
                        }
                    }
                }
            }
        }
        return false;
    }

    // TC : O(M * N^2)
    // SC : O(N)
    bool optimal(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, unordered_set<int>> mpp; // {j, {from j+1 to n}}
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mat[i][j] == 1) {
                    for (int j2 = j + 1; j2 < n; j2 ++) {
                        if (mat[i][j2] == 1) {
                            if (mpp.count(j) && mpp[j].count(j2)) {
                                return true;
                            } else {
                                mpp[j].insert(j2); 
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
  public:
    bool ValidCorner(vector<vector<int>> &mat) {
        // return brute(mat);
        return optimal(mat);
    }
};