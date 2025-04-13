// https://leetcode.com/problems/sliding-window-median/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(N)
    vector<double> approach_1(vector<int> &nums, int k) {
        int n = nums.size();
        int size = (n - k + 1);
        multiset<long> maxMst, minMst;
        vector<double> result(size, 0.0);
        int i = 0, j = 0;
        while (j < n) {
            if (maxMst.empty() || nums[j] < *maxMst.rbegin()) {
                maxMst.insert(nums[j]);
            } else {
                minMst.insert(nums[j]);
            }

            // Balance the set
            if (maxMst.size() > 1 + minMst.size()) {
                auto it = prev(maxMst.end());
                minMst.insert(*it);
                maxMst.erase(it);
            } else if (minMst.size() > maxMst.size()) {
                auto it = minMst.begin();
                maxMst.insert(*it);
                minMst.erase(it);
            }

            if (j - i + 1 == k) {
                double val = 0.0; 
                if (k %2) {
                    val = *maxMst.rbegin();
                } else {
                    val = ((double)*maxMst.rbegin() + (double)*minMst.begin()) / 2.0;
                }
                result[i]  = val;

                // Remove the leftmost element of the window
                if (maxMst.find(nums[i]) != maxMst.end()) {
                    auto it = maxMst.find(nums[i]);
                    maxMst.erase(it);
                } else {
                    auto it = minMst.find(nums[i]);
                    minMst.erase(it);
                }
                
                i ++;
            }
            j ++;
        }
        return result;
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        return approach_1(nums, k);
    }
};