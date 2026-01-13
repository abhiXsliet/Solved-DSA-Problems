// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> dq;
        vector<int> result;
        int i = 0, j = 0;
        while (j < n) {
            while (!dq.empty() && arr[dq.back()] <= arr[j]) {
                dq.pop_back();
            }
            dq.push_back(j);
            if (j - i + 1 == k) {
                result.push_back(arr[dq.front()]);
                if (dq.front() <= i) dq.pop_front();
                i ++;
            }
            j ++;
        }
        return result;
    }
};