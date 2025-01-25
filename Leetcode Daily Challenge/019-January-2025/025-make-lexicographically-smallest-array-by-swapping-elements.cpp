// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2 * X) Average time of while loop runnig
    // SC : O(1)
    vector<int> approach_1(vector<int>& nums, int limit) {
        int n = nums.size();
        for (int i = 0; i < n; i ++) {
            while (true) {
                int ele = nums[i];
                int idx = -1;
                for (int j = i + 1; j < n; j ++) {
                    if (abs(nums[i] - nums[j]) <= limit && nums[j] < ele) {
                        ele = nums[j];
                        idx = j;
                    }
                }
                if (idx != -1) {
                    swap(nums[i], nums[idx]);
                } else {
                    break;
                }
            }
        }
        return nums;
    }

    // TC : O(N*log(N))
    // SC : O(N)
    vector<int> approach_2(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> store = nums;        
        sort(begin(store), end(store));

        int groupNo = 0;
        unordered_map<int, int> numToGroup;
        numToGroup[store[0]] = groupNo;

        unordered_map<int, list<int>> groupToList;
        groupToList[groupNo].push_back(store[0]);

        for (int i = 1; i < n; i ++) {
            if (abs(store[i] - store[i - 1]) > limit) {
                groupNo += 1;
            }
            numToGroup[store[i]] = groupNo;
            groupToList[groupNo].push_back(store[i]);
        }

        vector<int> result(n);
        for (int i = 0; i < n; i ++) {
            int group = numToGroup[nums[i]];
            result[i] = *groupToList[group].begin();    // get the smallest no. from group
            groupToList[group].pop_front();
        }
        return result;
    }
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // return approach_1(nums, limit);     // BRUTE

        return approach_2(nums, limit);     // Optimal
    }
};