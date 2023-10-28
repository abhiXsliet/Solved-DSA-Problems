// https://www.codingninjas.com/studio/problems/longest-successive-elements_6811740


#include <bits/stdc++.h>
using namespace std;

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
int solve_better(vector<int>& a) {
    int n = a.size();

    sort(a.begin(), a.end());

    int longest = 1;
    int lastSmallest = INT_MIN;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] - 1 == lastSmallest) {
            cnt++;
            lastSmallest = a[i];
        }
        else if (a[i] != lastSmallest) {
            lastSmallest = a[i];
            cnt = 1;
        }

        longest = max(longest, cnt);
    }

    return longest;
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

int longestSuccessiveElements(vector<int>&a) {
    // return solve_brute(a);

    // return solve_better(a);

    return solve_optimal(a);
}