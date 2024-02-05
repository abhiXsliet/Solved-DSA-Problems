// https://leetcode.com/contest/biweekly-contest-123/problems/find-the-number-of-ways-to-place-people-i/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    bool isValid(vector<vector<int>>& points, int i, int j) {
        int ax = points[i][0];
        int ay = points[i][1];
        
        int bx = points[j][0];
        int by = points[j][1];
        
        if (ax > bx || ay < by) return false;
        return true;
    }
    
    bool calc(vector<vector<int>>& points, int i, int j, int k) {
        int ax = points[i][0];
        int ay = points[i][1];
        
        int bx = points[j][0];
        int by = points[j][1];
        
        int kx = points[k][0];
        int ky = points[k][1];
        
        // vertical line
        if (ax == bx) {
            if (kx == ax && (by <= ky && ky <= ay)) 
                return false;
            return true;
        }

        // horizontal line
        if (ay == by) {    
            if ((ky == ay) && (ax <= kx && kx <= bx))  
                return false;
            return true;
        }
        
        // rectangular area
        if ((ax <= kx && kx <= bx) && (by <= ky && ky <= ay)) { 
            return false;
        }
        return true;
    }
public:
    // TC : O(N^3)
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                    
                if (i != j) {
                    
                    if (isValid(points, i, j)) {
                    
                        bool flag = false;
                        for (int k = 0; k < n; k++) {

                            if (k != i && k != j) {

                                if (!calc(points, i, j, k)) {
                                    flag = true;
                                    break;
                                }

                            }
                        }
                    
                        if (flag == false) 
                            ans ++;
                    }
                }
                
            }
        }
        return ans;
    }
};