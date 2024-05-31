// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^3)
    // SC : O(1)
    int better(vector<int>& arr, int n) {
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            for (int k = i + 1; k < n; k ++) {
                // check xor from i to k is 0 or not?
                int xor_val = 0;
                for (int j = i; j <= k; j ++) {
                    xor_val ^= arr[j];
                }
                if (xor_val == 0) {
                    ans += k - i;
                }
            }
        }
        return ans;
    }

    // TC : O(N^2)
    // SC : O(N)
    int optimal(vector<int>& arr, int n) {
        vector<int> prefXor(n + 1, 0);
        for (int i = 1; i < n + 1; i ++) {
            prefXor[i] = prefXor[i - 1] ^ arr[i - 1];
        }

        int tripletCnt = 0;
        for (int i = 0; i < n; i ++) {
            for (int k = i + 1; k <= n; k ++) {

                // Eliminate for-loop for calculating xor using prefXor
                if (prefXor[k] == prefXor[i]) {
                    tripletCnt += k - i - 1;
                }
            }
        }
        return tripletCnt;
    }

    // TC : O(N^2)
    // SC : O(1)
    int optimal_2(vector<int>& arr, int n) {
        int tripletCnt = 0;
        for (int i = 0; i < n; i++) {
            int xorVal = 0;
            for (int j = i; j < n; j ++) {
                xorVal ^= arr[j];
                if (xorVal == 0) {
                    tripletCnt += j - i;
                }
            }
        }
        return tripletCnt;
    }

    // TC : O(N)
    // SC : O(N)
    int optimal_3(vector<int>& arr, int n) {
        int tripletCnt = 0;
        
        vector<int> prefXor(n + 1, 0);
        // sumOfIdx   : storing the indices sum where value of xor is same
        // countOfXor : storing the number of occurances of xor previously
        unordered_map<int, int> sumOfIdx, countOfXor;
        sumOfIdx[0] = 0, countOfXor[0] = 1;

        for (int k = 1; k <= n; k ++) {
            prefXor[k]  = prefXor[k - 1] ^ arr[k - 1];
            
            tripletCnt += k * countOfXor[prefXor[k]] - sumOfIdx[prefXor[k]] - countOfXor[prefXor[k]];

            countOfXor[prefXor[k]] ++;
            sumOfIdx[prefXor[k]] += k;
        }
        return tripletCnt;
    }
public:
    int countTriplets(vector<int>& arr) {
        // brute : use three for loops

        // return better(arr, arr.size());  // find cnt of all subarray of xor = 0

        // return optimal(arr, arr.size()); // Use prefix_xor to store xor of all previous elements

        // return optimal_2(arr, arr.size());  // Use Subarray sum logic

        return optimal_3(arr, arr.size());  // Use Hashmap to reduce time and one pass solution
    }
};