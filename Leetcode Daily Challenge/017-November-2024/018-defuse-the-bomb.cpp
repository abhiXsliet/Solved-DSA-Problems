// https://leetcode.com/problems/defuse-the-bomb/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * K)
    // SC : O(1)
    vector<int> brute(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        
        if (k == 0) return result;
        
        for (int i = 0; i < n; i ++) {
            int sum = 0;
            if (k < 0) {
                for (int j = i - 1; j >= i - abs(k); j --) {
                    sum += code[(j + n) % n];
                }
            } else {
                for (int j = i + 1; j <= i + k; j ++) {
                    sum += code[j % n];
                }
            }
            result[i] = sum;
        }

        return result;
    }

    // TC : O(N)
    // SC : O(1)
    vector<int> optimal(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if (k == 0) return result;

        int windowSum = 0;
        int l = -1, r = -1;
        if (k < 0) {
            l = n - abs(k);
            r = n - 1;
        } else {
            l = 1;
            r = k;
        }
        // calculate window sum
        for (int i = l; i <= r; i ++) {
            windowSum += code[i];
        }

        for (int i = 0; i < n; i ++) {
            result[i] = windowSum;

            windowSum -= code[l % n];
            windowSum += code[(r + 1) % n];
            l ++;
            r ++;
        }

        return result;
    }
public:
    vector<int> decrypt(vector<int>& code, int k) {
        // return brute(code, k);
        return optimal(code, k);    // sliding window
    }
};