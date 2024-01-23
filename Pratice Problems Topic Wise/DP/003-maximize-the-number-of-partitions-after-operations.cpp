// https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(2^N + 26)
    // SC : O(M) Where M = unique states -> Recursive Stack
    int solve_rec(string& s, int k, int idx, int uniqueChars, bool canChange) {
        if (idx >= s.length()) return 0;

        int charIdx           = s[idx] - 'a';
        int new_uniqueChar    = (uniqueChars | (1 << charIdx));
        int new_uniqueCharCnt = __builtin_popcount(new_uniqueChar);
        int result = 0;

        if (new_uniqueCharCnt > k) {
            result = 1 + solve_rec(s, k, idx + 1, (1 << charIdx), canChange); 
        }
        else {
            result = solve_rec(s, k, idx + 1, new_uniqueChar, canChange);
        }

        if (canChange == true) {
            // 0....25 -> a....z
            for (int newCharIdx = 0; newCharIdx < 26; newCharIdx++) {

                int new_uniqueChar_set = (uniqueChars | (1 << newCharIdx));
                int new_uniqueChar_cnt = __builtin_popcount(new_uniqueChar_set);

                if (new_uniqueChar_cnt > k) {
                    result = max( result, 1 + solve_rec(s, k, idx+1, (1 << (newCharIdx)), false) );
                }
                else {
                    result = max( result, solve_rec(s, k, idx+1, new_uniqueChar_set, false) );
                }
            }
        }

        return result;
    }

    // bits used by indexes + bits used by uniqueChars(= 26) + bits used by canChange(= 1)
    // 1 << 27 => 27th bit is set and bit-0th is used for canChange, 
    // bit-1th to 26th will be used for uniqueChars and from bit-27th is used for index representation
    unordered_map<long long, int> mpp;

    // TC : O(N * uniqueChars)
    // SC : O(M + N) Where M = uniqueChars & N = size of map
    int solve_mem(string& s, int k, long long idx, long long uniqueChars, bool canChange) {
        // this key will be unique for every indices
        long long key = ((idx << 27) | (uniqueChars << 1) | canChange);
        
        if (mpp.find(key) != mpp.end()) {
            return mpp[key];
        }

        if (idx >= s.length()) return 0;

        int charIdx           = s[idx] - 'a';
        int new_uniqueChar    = (uniqueChars | (1 << charIdx));
        int new_uniqueCharCnt = __builtin_popcount(new_uniqueChar);
        int result = 0;

        if (new_uniqueCharCnt > k) {
            result = 1 + solve_mem(s, k, idx + 1, (1 << charIdx), canChange); 
        }
        else {
            result = solve_mem(s, k, idx + 1, new_uniqueChar, canChange);
        }

        if (canChange == true) {
            // 0....25 -> a....z
            for (int newCharIdx = 0; newCharIdx < 26; newCharIdx++) {

                int new_uniqueChar_set = (uniqueChars | (1 << newCharIdx));
                int new_uniqueChar_cnt = __builtin_popcount(new_uniqueChar_set);

                if (new_uniqueChar_cnt > k) {
                    result = max( result, 1 + solve_mem(s, k, idx+1, (1 << (newCharIdx)), false) );
                }
                else {
                    result = max( result, solve_mem(s, k, idx+1, new_uniqueChar_set, false) );
                }
            }
        }

        return mpp[key] = result;
    }
public:
    int maxPartitionsAfterOperations(string s, int k) {
        // return solve_rec(s, k, 0, 0, 1) + 1; // +1 for the last char of string

        return solve_mem(s, k, 0, 0, 1) + 1;
    }
};