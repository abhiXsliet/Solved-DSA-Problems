// https://leetcode.com/problems/longest-consecutive-sequence/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool linearSearch(int tar, vector<int>& nums) {
        for (int num : nums)
            if (num == tar) return true;

        return false;
    }

    // TC = O(N*N)
    // SC = O(1)
    int solve_brute(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 0) return 0;

        int maxCnt = 1;

        for (int i = 0; i < n; i++) {
            int curr_ele = nums[i];
            int cnt = 0;
            
            while(linearSearch(curr_ele, nums)) {
                cnt++;
                curr_ele++;
            }
            maxCnt = max(maxCnt, cnt);
        }

        return maxCnt;
    }

    // TC = O(N*log(N))
    // SC = O(1)
    int solve_better(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 0) return 0;

        sort(begin(nums), end(nums));

        int maxCnt = 1;
        int lastSmaller = INT_MIN;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int curr_ele = nums[i];

            if (curr_ele - 1 == lastSmaller) {
                cnt++;
                lastSmaller = curr_ele;
            }
            else if (curr_ele != lastSmaller) {
                cnt = 1;
                lastSmaller = curr_ele;
            }

            maxCnt = max(maxCnt, cnt);
        }

        return maxCnt;
    }

    // TC = O(N)
    // SC = O(N)
    int solve_optimal(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        st.insert(begin(nums), end(nums));

        int maxCnt = 0;

        for (int curr_ele : st) {

            int cnt = 0;
            if (st.find(curr_ele - 1) == st.end()) {

                // if the prev_ele is not present in set
                // then we serach for the curr_ele to make a chain of LCS
                while(st.find(curr_ele) != st.end()) {
                    curr_ele++;
                    cnt++;
                }
            }

            maxCnt = max(maxCnt, cnt);
        }

        return maxCnt;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        // return solve_brute(nums);

        // return solve_better(nums);

        return solve_optimal(nums);
    }
};