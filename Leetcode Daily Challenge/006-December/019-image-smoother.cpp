// https://leetcode.com/problems/image-smoother/



#include <bits/stdc++.h>
using namespace std; 

class Solution {
private:
    vector<vector<int>> directions
    {
        {-1, -1}, {-1, 0}, {-1, 1}, 
        {0 , -1}, {0 , 0}, {0 , 1}, 
        {1 , -1}, {1 , 0}, {1 , 1}
    };

    // TC : O(M*N)
    // SC : O(M*N)
    vector<vector<int>> solve_approach_1(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> result(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int sum_neighbour = 0;
                int cnt_neighbour = 0;

                for (auto it : directions) {
                    int new_i = i + it[0];
                    int new_j = j + it[1];

                    if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {

                        sum_neighbour += img[new_i][new_j];
                        cnt_neighbour ++;
                    }
                }

                result[i][j] = sum_neighbour / cnt_neighbour;
            }
        }

        return result;
    }

    // TC : O(N*M)
    // SC : O(N)
    vector<vector<int>> solve_approach_2(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<int> temp(n, 0);
        int prevCorner = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int sum_neigh = 0;
                int cnt_neigh = 0;

                // Bottom (i+1)th row neighbour -> [i+1][j-1], [i+1][j], [i+1][j+1]
                if (i + 1 < m ) {
                    
                    if (j - 1 >= 0) {
                        sum_neigh += img[i + 1][j - 1];
                        cnt_neigh ++;
                    }

                    sum_neigh += img[i + 1][j];
                    cnt_neigh ++;

                    if (j + 1 < n) {
                        sum_neigh += img[i + 1][j + 1];
                        cnt_neigh ++;
                    }
                }

                // Just right neigh [i][j+1]
                if (j + 1 < n) {

                    sum_neigh += img[i][j + 1];
                    cnt_neigh ++;
                }

                // Current cell [i][j]
                sum_neigh += img[i][j];
                cnt_neigh ++;

                // Left neigh -> [i][j - 1];
                if (j - 1 >= 0) {

                    sum_neigh += temp[j - 1];
                    cnt_neigh ++;
                }

                // Top neigh(i - 1)th row [i - 1][j - 1], [i - 1][j], [i - 1][j + 1]
                if (i - 1 >= 0) {
                    // prevCorner -> [i - 1][j - 1]
                    if (j - 1 >= 0) {

                        sum_neigh += prevCorner;
                        cnt_neigh ++;
                    }

                    sum_neigh += temp[j];
                    cnt_neigh ++;

                    if (j + 1 < n) {
                        
                        sum_neigh += temp[j + 1];
                        cnt_neigh ++;
                    }
                }

                // Store prev value of temp
                if (i - 1 >= 0)
                    prevCorner = temp[j];

                // Store current value of [i][j]
                temp[j] = img[i][j];

                img[i][j] = sum_neigh / cnt_neigh;
            }
        }

        return img;
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // return solve_approach_1(img);


        return solve_approach_2(img);
    }
};