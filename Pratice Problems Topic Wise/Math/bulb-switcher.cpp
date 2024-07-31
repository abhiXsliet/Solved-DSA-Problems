// https://leetcode.com/problems/bulb-switcher/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(sqrt(N))
    // SC : O(1)
    int approach_1(int n) {
        if (n == 0) return 0;

        int cntOnBulbs = 1;     // 1, 2, 3 , 4 , 5 , ....
        int sequences  = 3;     // 3, 5, 7 , 9 , 11, ....
        int totalRange = 3;     // 3, 8, 15, 24, 35, .... 

        while (totalRange < n) { // 4, 9, 16, 25, 36, .... loop continues
            sequences  += 2;
            cntOnBulbs += 1;
            totalRange  = sequences + totalRange;
        }

        return cntOnBulbs;
    }
    
    // TC : sqrt(N)
    // SC : O(1)
    int approach_2(int n) {
        return sqrt(n);
    }
public:
    int bulbSwitch(int n) {
        // return approach_1(n);


        return approach_2(n);   // ON BULBS : 1, 4, 9, 16, 25, .... => perfect squares
    }
};