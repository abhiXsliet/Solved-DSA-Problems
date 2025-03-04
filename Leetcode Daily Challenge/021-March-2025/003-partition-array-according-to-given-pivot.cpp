// https://leetcode.com/problems/partition-array-according-to-given-pivot/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // TC : O(N)
    // SC : O(N)
    vector<int> approach_1(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> smaller, greater;
        int pivotCnt = 0;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == pivot) {
                pivotCnt ++;
                continue;
            }
            if (nums[i] < pivot) {
                smaller.push_back(nums[i]);
            } else {
                greater.push_back(nums[i]);
            }
        }
        vector<int> result;
        for (int &num : smaller) {
            result.push_back(num);
        }
        for (int i = 0; i < pivotCnt; i ++) {
            result.push_back(pivot);
        }
        for (int &num : greater) {
            result.push_back(num);
        }
        return result;
    }

    // TC : O(N)
    // SC : O(1)
    vector<int> approach_2(vector<int>& nums, int pivot) {
        int n = nums.size();
        int pivotCnt = 0, smallCnt = 0;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == pivot) {
                pivotCnt ++;
            } else if (nums[i] < pivot) {
                smallCnt ++;
            }
        }
        // filled pivot : so need to handle for pivot
        vector<int> result(n, pivot);
        int idx = 0;
        for (int &num : nums) {
            if (idx < n && num < pivot) {
                result[idx ++] = num;
            }
        }

        // Increase index till pivot cnt
        int K = pivotCnt;
        for (; idx < n && K; idx ++) {
            if (result[idx] == pivot) {
                K --;
            }
        }
        // fill all the greater element in sequence
        for (int &num : nums) {
            if (idx < n && num > pivot) {
                result[idx ++] = num;
            }
        }
        return result;
    }

    // TC : O(N)
    // SC : O(1)
    vector<int> approach_3(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n, pivot);
        int i = 0, j = n - 1;
        int res_i = 0, res_j = n - 1;
        while (i < n) {
            if (nums[i] < pivot) result[res_i ++] = nums[i];
            if (nums[j] > pivot) result[res_j --] = nums[j];
            i ++;
            j --;
        }
        return result;
    }
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // return approach_1(nums, pivot);  // BRUTE
        // return approach_2(nums, pivot);  // BETTER
        return approach_3(nums, pivot);  // OPTIMAL : more or less similar to sort colors
    }
};