// https://leetcode.com/problems/xor-queries-of-a-subarray/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(M * N) Where M = No. of Queries & N = Length of array
    // SC : O(M)
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int m = queries.size();

        vector<int> pXor(n, arr[0]);

        for (int i = 1; i < n; i ++) {
            pXor[i] = pXor[i - 1] ^ arr[i];
            cout << pXor[i] << " ";
        }

        vector<int> result(m, 0);

        for (int i = 0; i < m; i ++) {
            int left  = queries[i][0];
            int right = queries[i][1];

            result[i] = (left == 0 ? 0 : pXor[left - 1]) ^ pXor[right];
        }

        return result; 
    }
};