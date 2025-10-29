// https://leetcode.com/problems/smallest-number-with-all-set-bits/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAllBitsSet(int x) {
        return (x & (x+1)) == 0;
    }

    // TC : O(result - n)
    int approach_1(int n) {
        int result = n;

        while(!isAllBitsSet(result)) {
            result++;
        }

        return result;
    }

    // TC : O(log(N))
    int approach_2(int n) {
        int result = 1;

        while(result < n) {
            result = 2*result + 1;
        }

        return result;
    }
    
    int smallestNumber(int n) {
        // return approach_1(n);
        return approach_2(n);
    }
};