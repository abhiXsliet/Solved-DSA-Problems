// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * N)
    // SC : O(N)
    vector<int> approach_1(vector<int>& A, vector<int>& B) {
        int n = B.size();
        vector<int> result(n, 0);
        unordered_set<int> st;
        for (int i = 0; i < n; i ++) {
            st.insert(A[i]);
            if (A[i] == B[i]) {
                if (i > 0) 
                    result[i] += result[i - 1] + 1;
                else 
                    result[i] = 1;
            } else {
                int available = 0;
                for (int j = i; j >= 0; j --) {
                    if (st.count(B[j])) 
                        available += 1;
                }
                result[i] = available;
            }
        }
        return result;
    }

    // TC : O(N)
    // SC : O(N)
    vector<int> approach_2(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0);
        vector<int> result(n, 0);
        
        result[0] = (A[0] == B[0] ? 1 : 0);
        freq[A[0]] ++, freq[B[0]] ++;

        for (int i = 1; i < n; i ++) {
            result[i] += A[i] == B[i] ? result[i - 1] + 1 : result[i - 1];
            if (freq[A[i]]) result[i] ++;
            if (freq[B[i]]) result[i] ++;
            freq[A[i]] ++;
            freq[B[i]] ++;
        }
        return result;
    }
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // Brute : N^3 (using 3 for loops)
        // return approach_1(A, B);    // Better
        return approach_2(A, B);    // Optimal
    }
};