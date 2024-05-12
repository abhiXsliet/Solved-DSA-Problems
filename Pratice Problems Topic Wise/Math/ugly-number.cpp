// https://leetcode.com/problems/ugly-number/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(log(N))
    bool isUgly(int n) {
        if (n <= 0) return 0;
        while (n > 1) {
            if (n % 2 == 0) n /= 2;
            else if (n % 3 == 0) n /= 3;
            else if (n % 5 == 0) n /= 5;
            else return 0; 
        }
        return 1;
    }
};