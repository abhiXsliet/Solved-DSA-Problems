// https://leetcode.com/problems/decode-ways/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int t[101];

    // TC : O(N)
    // SC : O(N) -> max recursive depth
    int solve_mem(string& s, int n, int idx) {
        if (t[idx] != -1) 
            return t[idx];

        if (idx == n) { // one valid split done
            return t[idx] = 1;
        }

        if (s[idx] == '0') {    // split can't be possible since '0' is not mapped with any integer
            return t[idx] = 0;
        }

        // spliting only ith char
        int result = solve_mem(s, n, idx+1);

        // splitting 'i' + 1th char
        if (idx + 1 < n) {
            if (s[idx] == '1' ||( s[idx] == '2' && s[idx + 1] <= '6' )) {
                result += solve_mem(s, n, idx + 2);
            }
        }

        return t[idx] = result;
    }

    // TC : O(N)
    // SC : O(N)
    int solve_tab(string& s) {
        int n = s.length();
        vector<int> t(n+1, 0);
        
        // t[i] = no. of ways to decode string i to n
        t[n] = 1;

        for (int idx = n - 1; idx >= 0; idx--) {
            if (s[idx] == '0') {
                t[idx] = 0;
            }
            else {
                t[idx] = t[idx + 1];

                if (idx + 1 < n) {
                    if (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6'))
                        t[idx] += t[idx + 2];
                }
            }
        }
        // decoding ways of string s from 0 to n
        return t[0];
    }

    int solve_1(string& s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        return solve_mem(s, n, 0);
    }
public:
    int numDecodings(string s) {
        // return solve_1(s);

        return solve_tab(s);
    }
};