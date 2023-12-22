// https://leetcode.com/problems/maximum-score-after-splitting-a-string/



#include <bits/stdc++.h>
using namespace std; 

class Solution {
private:
    // TC : O(N*N)
    // SC : O(1)
    int solve_brute(string& s) {
        int n = s.length();
        int maxi = INT_MIN;
        for (int i = 0; i < n-1; i++) {
            int idx = 0;
            int cntZero = 0;
            while (idx <= i) {
                if (s[idx] == '0') {
                    cntZero ++;
                }
                idx ++;
            }

            idx = i + 1;
            int cntOne = 0;
            while (idx < n) {
                if (s[idx] == '1') {
                    cntOne ++;
                }
                idx ++;
            }

            maxi = max(maxi, cntOne + cntZero);
        }
        return maxi;
    }

    // TC : O(N) -> Two Pass Solution
    // SC : O(1)
    int solve_better(string& s) {
        int n = s.length();
        int totalOnes = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') 
                totalOnes ++;
        }
        
        // 1-liner to count the total no. of 1's
        // int totalOnes = count(begin(s), end(s), '1');

        int result = INT_MIN;

        int cntZeros = 0;
        int cntOnes  = 0;
        for (int i = 0; i < n-1; i++) {
            if (s[i] == '0') 
                cntZeros ++;
            else
                cntOnes ++;

            int rightOnes = totalOnes - cntOnes;

            result = max(result, cntZeros + rightOnes);
        }

        return result;
    }

    // TC : O(N) -> One Pass Solution
    // SC : O(1)
    // total_1s = left_1s + right_1s
    // for every ith idx = right_1s + left_0s   ----------- (1)
    //                   = total_1s - left_1s + left_0s [using eq. 1]
    int solve_optimal(string& s) {
        int n = s.length();

        int result = INT_MIN;

        int cntOnes  = 0;
        int cntZeros = 0;
        
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') 
                cntZeros ++;
            else cntOnes ++;

            result = max(result, cntZeros - cntOnes);
        }

        // if the last char is also a '1' 
        if (s[n - 1] == '1') 
            cntOnes ++;

        return result + cntOnes;
    }
public:
    int maxScore(string s) {
        // return solve_brute(s);

        // return solve_better(s);

        return solve_optimal(s);
    }
};