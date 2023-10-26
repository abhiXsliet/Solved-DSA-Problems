// https://leetcode.com/problems/binary-trees-with-factors/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
    int solve(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, long long> mpp; // <arr[i], no. of BT> 
        
        sort(begin(arr), end(arr));
        
        mpp[arr[0]] = 1;

        for (int i = 1; i < n; i++) {
            int root = arr[i];
            mpp[root] = 1;  // one way to form the root

            for (int j = 0; j < i; j++) {
                
                int leftChild = arr[j];
                int rightChild = arr[i] / leftChild;

                if (root % leftChild == 0 && mpp.find(rightChild) != mpp.end()) {
                    mpp[root] += mpp[leftChild] * mpp[rightChild];
                }
            }
        }

        long result = 0;
        for (auto& it : mpp) {
            result = (result + it.second) % MOD;
        }

        return result;
    }
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        return solve(arr);
    }
};