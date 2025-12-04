// https://leetcode.com/problems/count-collisions-on-a-road/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int approach_1(string& dir, int n) {
        int result = 0;
        int R_cnt  = 0;
        int S_cnt  = 0;

        for (char& ch : dir) {
            if (ch == 'R') {
                R_cnt ++;
                continue;
            }

            if (ch == 'S') {
                result += R_cnt;
                S_cnt  = 1;
                R_cnt  = 0;
                continue;
            }

            if (R_cnt > 0) {
                result += 2;
                result += (R_cnt - 1);
                S_cnt  = 1;
                R_cnt  = 0;
            }
            else {
                if (S_cnt) result ++;
            }
        }
        return result;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(string& dir, int n) {
        int L_cnt  = 0;
        int R_cnt  = n - 1;
        int result = 0;

        while (L_cnt <= R_cnt && dir[L_cnt] == 'L') L_cnt ++;

        while (L_cnt <= R_cnt && dir[R_cnt] == 'R') R_cnt --;

        for (int i = L_cnt; i <= R_cnt; i++) {
            result += dir[i] != 'S';
        }

        return result;
    }
public:
    int countCollisions(string directions) {
        // return approach_1(directions, directions.length());   
        return approach_2(directions, directions.length());   
    }
};