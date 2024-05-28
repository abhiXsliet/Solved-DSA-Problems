// https://leetcode.com/problems/get-equal-substrings-within-budget/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(vector<int>& prefSum, int maxCost, int mid) {
        int left = 0, right = mid;
        bool flag = 0;

        while (right < prefSum.size()) {
            int sum = prefSum[right] - prefSum[left];
            if (sum <= maxCost) {
                flag = 1;
                break;
            }
            left++;
            right++;
        }
        return flag;
    }

    // TC : O(N*log(N))
    // SC : O(N)
    int solve_approach_1(string& s, string& t, int maxCost) {
        int n = s.length();
        int result = 0;
        
        // store the cost of each len
        vector<int> prefSum (n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefSum[i] = prefSum[i - 1] + abs(s[i-1] - t[i-1]);
        }

        int low = 0, high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(prefSum, maxCost, mid)) {
                result = mid;  // store the answer & try to increase the length
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return result;
    }
    
    // TC : O(N)
    // SC : O(1)
    int solve_approach_2(string& s, string& t, int maxCost) {
        int n = s.length();
        int result = 0;
        int left = 0;
        int window = 0;

        for (int right = 0; right < n; right++) {
            window += abs(s[right] - t[right]);
            while (window > maxCost) {
                window -= abs(s[left] - t[left]);
                left ++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
public:
    int equalSubstring(string s, string t, int maxCost) {
        // return solve_approach_1(s, t, maxCost);

        return solve_approach_2(s, t, maxCost);
    }
};