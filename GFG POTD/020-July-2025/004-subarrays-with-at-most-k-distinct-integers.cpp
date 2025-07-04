// https://www.geeksforgeeks.org/problems/subarrays-with-at-most-k-distinct-integers/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(K) where K is the number of distinct integers
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mpp;
        int count = 0;
        int i = 0, j = 0;
        while (j < n) {
            mpp[arr[j]] ++;
            while (i < j && mpp.size() > k) {
                mpp[arr[i]] --;
                if (!mpp[arr[i]]) mpp.erase(arr[i]);
                i ++;
            }
            count += (j - i + 1);
            j ++;
        }
        return count;
    }
};