// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int solve_approach_1(string& s) {
        int n = s.length();

        int cnt1   = 0;
        int cnt2   = 0;

        for (int i = 0; i < n; i++) {
            // Consider Binary String Starting With '0' -> '010101'
            // At Every Even Indices -> 0 & At Every Odd Indices -> 1
            if (i % 2 == 0) {
                if (s[i] != '0') cnt1++;
            }
            else {
                if (s[i] != '1') cnt1++;
            }

            // Consider Binary String Starting With '1' -> '1010101'
            // Even Indices -> '1' & Odd Indices -> '0'
            if (i % 2 == 0) {
                if (s[i] != '1') cnt2++;
            }
            else {
                if (s[i] != '0') cnt2++;
            }
        }

        return min(cnt1, cnt2);
    }

    // TC : O(N)
    // SC : O(1)
    int solve_approach_2(string& s) {
        int n = s.length();

        int start_with_0 = 0;   // 010101...
        int start_with_1 = 0;   // 101010...

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {   // Even idices : 0
                if (s[i] != '0') start_with_0++;
            }
            else {  // Odd Indices : 1
                if (s[i] != '1') start_with_0++;
            }
        }
        
        start_with_1 = n - start_with_0;

        return min(start_with_0, start_with_1);
    }
public:
    int minOperations(string s) {
        // return solve_approach_1(s);

        return solve_approach_2(s);
    }
};