// https://leetcode.com/problems/frequency-of-the-most-frequent-element/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int bSearch(vector<int>& nums, int target_idx, int k, vector<long>& prefixSum) {
        int low  = 0;
        int high = target_idx;

        // elements have to make equal till best_idx
        int best_idx = target_idx;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // count of element till target_idx
            long windowLen = target_idx - mid + 1;

            // if array elements made equal to target_ele
            long windowSum = windowLen * nums[target_idx];
            
            // original sum of elements of array
            long totalSum  = prefixSum[target_idx] - prefixSum[mid] + nums[mid];

            int operationCnt = windowSum - totalSum;

            if (operationCnt > k) {
                low = mid + 1;
            }
            else {
                best_idx = mid;
                high = mid - 1;
            }
        }

        // total no. of equal elements 
        int freq = target_idx - best_idx + 1;

        return freq;
    }

    // TC = O(N * log(N))
    // SC = O(N) -> to store the prefix sum
    int solve_optimal_1_way_1(vector<int>& nums, int k) {
        int n = nums.size();

        // Step - 1 : Sort the array
        sort(begin(nums), end(nums));

        // Step - 2 : Calcuate the prefix sum
        vector<long> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        int maxFreq = INT_MIN;

        // Step - 3 : Consider every indices element
        for (int target_idx = 0; target_idx < n; target_idx++) {

            int freq = bSearch(nums, target_idx, k, prefixSum);

            maxFreq  = max(maxFreq, freq);
        }

        return maxFreq;
    }

    // To Check req. operation is less than the given value 'k'
    // Index * Prefix Sum before that index <= k
    bool isPossible_to_form_window(vector<int>& nums, int k, int mid) {
        // sum of all elements of array
        long long totalSum = 0;

        long long windowSum  = 0;

        for (int i = 0; i < mid; i++) {
            totalSum += nums[i];
        }

        // last element of window * index
        windowSum = 1LL * nums[mid - 1] * mid;

        if (windowSum - totalSum <= k) 
            return 1;

        int j = 0;
        for (int i = mid; i < nums.size(); i++) {

            totalSum -= nums[j];
            totalSum += nums[i];

            windowSum = 1LL * nums[i] * mid;

            if (windowSum - totalSum <= k)
                return 1;
            
            j++;
        }
        return 0;
    }

    // TC = O(N * log(N))
    // SC = O(1)

    // OBSERVATION: 
    // Try to create a window of maximum length within the range [min_ele, max_ele].
    // Initially, Try to form a window of size mid.
    // If it's possible, increase the lower (low = mid + 1); 
    // otherwise, decrease the upper (high = mid - 1).
    int solve_optimal_1_way_2(vector<int>& nums, int k) {
        int n    = nums.size();

        sort(begin(nums), end(nums));

        int low  = 1;
        int high = n;   // max window can be formed

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // if possible to form a window of size mid
            if (isPossible_to_form_window(nums, k, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    // TC = O(N * log(N))
    // SC = O(1)

    // OBSERVATION: 
    // If the product of the rightmost element and the window length
    // is >= to the sum of all elements in the window, then
    // include more elements from right side; 
    // otherwise, exclude the leftmost element.
    // And Max window length gets us the max possible freq of an element

    int solve_optimal_2(vector<int>& nums, int k) {
        int n = nums.size();

        // step - 1 : sort the array 
        sort(begin(nums), end(nums));

        long long currSum = 0;
        int maxFreq = INT_MIN;

        int left  = 0;
        int right = 0;

        // step - 2 : check following condition proceed 
        while (right < n) {
            currSum += nums[right];

            long target = nums[right];

            int windowLen   = right - left + 1;

            int operationCnt = (target * windowLen) - currSum;

            // shrink the window 
            if ( operationCnt > k ) {
                currSum -= nums[left];
                left  += 1;
            }

            maxFreq = max(maxFreq, right - left + 1);
            // expand the window
            right++;
        }

        return maxFreq;
    }

public:
    int maxFrequency(vector<int>& nums, int k) {
        // return solve_optimal_1_way_1(nums, k);

        // return solve_optimal_1_way_2(nums, k);

        return solve_optimal_2(nums, k);
    }
};