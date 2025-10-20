// https://www.geeksforgeeks.org/problems/number-of-bst-from-array/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    vector<int> catalan;

    void precomputeCatalan(int n) {
        catalan.resize(n + 1, 0);
        catalan[0] = catalan[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - 1 - j];
            }
        }
    }
  public:
    // TC : O(N*log(N))
    // SC : O(N)
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        precomputeCatalan(n);
        
        // Step 1: Make sorted copy
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        // Step 2: Map each value → its BST count
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int left = i;
            int right = n - i - 1;
            int totalBSTs = catalan[left] * catalan[right];
            mp[sortedArr[i]] = totalBSTs;
        }

        // Step 3: Build answer in original order
        vector<int> result;
        for (int val : arr) {
            result.push_back(mp[val]);
        }

        return result;
    }
};