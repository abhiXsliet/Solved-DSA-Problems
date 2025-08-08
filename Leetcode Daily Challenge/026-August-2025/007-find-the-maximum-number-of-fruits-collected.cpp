// https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;

    int t[1001][1001];

    int collectedByChild1(vector<vector<int>> &fruits) {
        int collect = 0;
        for (int i = 0; i < n; i ++) {
            collect += fruits[i][i];
        }
        return collect;
    }

    int collectedByChild2(int i, int j, vector<vector<int>> &fruits) {
        if (i >= n || j >= n || j < 0 || i >= j || i == n - 1 && j == n - 1) 
            return 0;

        if (t[i][j] != -1) return t[i][j];

        int op1 = fruits[i][j] + collectedByChild2(i + 1, j - 1, fruits);
        int op2 = fruits[i][j] + collectedByChild2(i + 1, j, fruits);
        int op3 = fruits[i][j] + collectedByChild2(i + 1, j + 1, fruits);

        return t[i][j] = max({op1, op2, op3});
    }

    int collectedByChild3(int i, int j, vector<vector<int>> &fruits) {
        if (i >= n || j >= n || i < 0 || i <= j || i == n - 1 && j == n - 1) 
            return 0;

        if (t[i][j] != -1) return t[i][j];

        int op1 = fruits[i][j] + collectedByChild3(i - 1, j + 1, fruits);
        int op2 = fruits[i][j] + collectedByChild3(i, j + 1, fruits);
        int op3 = fruits[i][j] + collectedByChild3(i + 1, j + 1, fruits);

        return t[i][j] = max({op1, op2, op3});
    }

    // TC : O(N^2)
    // SC : O(N^2)
    int approach_1(vector<vector<int>> &fruits) {
        memset(t, -1, sizeof(t));

        int result = 0;
        result += collectedByChild1(fruits);
        result += collectedByChild2(0, n - 1, fruits);
        result += collectedByChild3(n - 1, 0, fruits);

        return result;
    }

    // TC : O(N^2)
    // SC : O(N^2)
    int approach_2(vector<vector<int>> &fruits) {
        memset(t, 0, sizeof(t));

        int result = 0;
        
        // collections done by child-1
        for (int i = 0; i < n; i ++) {
            result += fruits[i][i];
        }

        // finding non-restricted regions for child-2 and child-3 because 
        // if they goes into these restricted regions then not able to reach destination [n - 1][n - 1] in exactly (n - 1) moves
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i < j) {
                    // since child-2 can't go to the region where (i + j < n - 1)
                    if (i + j >= n - 1) {   
                        t[i][j] = fruits[i][j];
                    }
                } else if (i > j) {
                    // since child-3 can't go to the region where (i + j < n - 1)
                    if (i + j >= n - 1) {   
                        t[i][j] = fruits[i][j];
                    }
                }
            }
        }

        // collections done by child-2
        for (int i = 1; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                t[i][j] += max({t[i - 1][j], t[i - 1][j - 1], ((j + 1 < n) ? t[i - 1][j + 1] : 0)});
            }
        }

        // collections done by child-3
        for (int j = 1; j < n; j ++) {
            for (int i = j + 1; i < n; i ++) {
                t[i][j] += max({t[i][j - 1], t[i - 1][j - 1], ((i + 1 < n) ? t[i + 1][j - 1] : 0)});
            }
        }

        return result + t[n - 2][n - 1] + t[n - 1][n - 2];
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();

        // return approach_1(fruits);  
        return approach_2(fruits);
    }
};