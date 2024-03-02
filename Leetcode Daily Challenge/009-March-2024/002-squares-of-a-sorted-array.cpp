// https://leetcode.com/problems/squares-of-a-sorted-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(1)
    vector<int> solve_brute(vector<int>& nums, int n) {
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }
        sort(begin(nums), end(nums));
        return nums;
    }

    // TC : O(N)
    // SC : O(N)
    vector<int> solve_optimal(vector<int>& nums, int n) {
        vector<int> result(n);
        int i = 0, j = n - 1, k = n - 1;
        while (k >= 0) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if (a > b) {
                result[k] = a;
                i ++;
            }
            else {
                result[k] = b;
                j --;
            }
            k --;
        }
        return result;
    }

    void countSort(vector<int>& arr, int exp) {
        vector<int> output(arr.size());
        vector<int> count(10, 0);

        for (int i = 0; i < arr.size(); i++) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }
    }

    int getMax(vector<int>& arr) {
        int max = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    void radixSort(vector<int>& arr) {
        int max = getMax(arr);

        for (int exp = 1; max / exp > 0; exp *= 10) {
            countSort(arr, exp);
        }
    }
    
    // TC : O(D * N) D is usually small (e.g., 10 for decimal numbers)
    // SC : O(N + 10) ~= O(N)
    vector<int> solve_radix(vector<int>& nums, int n) {
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }
        radixSort(nums);
        return nums;
    }
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // return solve_brute(nums, nums.size());

        // return solve_optimal(nums, nums.size());

        return solve_radix(nums, nums.size());
    }
};