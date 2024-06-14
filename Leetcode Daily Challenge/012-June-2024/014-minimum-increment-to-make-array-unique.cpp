// https://leetcode.com/problems/minimum-increment-to-make-array-unique/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(N)
    int brute(vector<int>& nums, int n) {
        unordered_set<int> st;
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            if (st.find(nums[i]) != st.end()) {
                int val = nums[i];
                while (st.find(val) != st.end()) {  // O(N)
                    val ++;
                }
                ans += val - nums[i];
                st.insert(val);
            } else {
                st.insert(nums[i]);
            }
        }
        return ans;
    }

    int brute_2(vector<int>& nums, int n) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int& num : nums) pq.push(num);

        int ans = 0;
        while (pq.size() > 1) {
            int firstEl  = pq.top(); pq.pop();
            int secondEl = pq.top(); pq.pop();

            if (firstEl == secondEl) {
                secondEl += 1;
                ans      += 1;
                pq.push(firstEl);
                pq.push(secondEl);
            } else {
                pq.push(secondEl);
            }
        }
        return ans;
    }

    // TC : O(N*log(N))
    // SC : O(1)
    int optimal_1(vector<int>& nums, int n) {
        int moves = 0;
        sort(begin(nums), end(nums));
        for (int i = 1; i < n; i ++) {
            // if (nums[i] == nums[i - 1]) {
            //     nums[i] += 1;
            //     moves   += 1;
            // } else if (nums[i] < nums[i - 1]) {
            //     moves  += nums[i - 1] - nums[i] + 1;
            //     nums[i] = nums[i - 1] + 1;
            // }

            // ------------- OR ---------------
            if (nums[i] <= nums[i - 1]) {
                moves  += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return moves;
    }

    // TC : O(maxi + n) ~= O(N)
    // SC : O(N)
    int optimal_2(vector<int>& nums, int n) {
        int maxi = *max_element(begin(nums), end(nums));
        vector<int> store(maxi + n, 0);
        for (int &num : nums) {
            store[num] ++;
        }
        int ans = 0;
        for (int i = 0; i < store.size(); i ++) {
            if (store[i] == 0 || store[i] == 1) continue;
            int extra = store[i] - 1;
            store[i + 1] += extra;
            ans += extra;
        }
        return ans;
    }
public:
    int minIncrementForUnique(vector<int>& nums) {
        // return brute(nums, nums.size());

        // return brute_2(nums, nums.size());

        // return optimal_1(nums, nums.size());     // SIMULATION

        return optimal_2(nums, nums.size());     // COUNTING SORT
    }
};