// https://leetcode.com/contest/weekly-contest-360/problems/furthest-point-from-origin/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve_1(string moves) {
        int n = moves.length();
        int L = 0;
        int R = 0;
        int Dash = 0;
        
        for(int i = 0; i < n; i++) {
            if (moves[i] == 'L') L++;
            if (moves[i] == 'R') R++;
            if (moves[i] == '_') Dash++;
        }
        
        if (L == R) return Dash;
        else if (L > R) return abs(L - R + Dash);
        else return abs(R - L + Dash);
    }

    int solve_2(string moves) {
        int n = moves.length();
        int pos = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if (moves[i] == 'L') pos--;
            else if (moves[i] == 'R') pos++;
            else cnt++;
        }
        return abs(pos + 0) + cnt;
    }

public:
    int furthestDistanceFromOrigin(string moves) {
        
        // return solve_1(moves);

        return solve_2(moves);
    }
};