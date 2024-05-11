// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<int, string> P;

    // TC : O(N*log(N))
    // SC : O(1)
    string approach_1(vector<string>& nums, int k) {
        int n = nums.size();
        auto cmp = [&](string& a, string& b) {
            if (a.length() == b.length()) {
                return a > b;
            }
            return a.length() > b.length();
        };
        sort(begin(nums), end(nums), cmp);
        return nums[k - 1];
    }

    // TC : O(N*log(K))
    // SC : O(1)
    string approach_2(vector<string>& nums, int k) {
        int n = nums.size();
        priority_queue<P, vector<P>, greater<P>> pq;

        for (string& num : nums) {
            pq.push({num.length(), num});

            if (pq.size() > k) pq.pop();
        }
        return pq.top().second;
    }

public:
    string kthLargestNumber(vector<string>& nums, int k) {
        // return approach_1(nums, k);     // SORTING

        return approach_2(nums, k);     // HEAP
    }
};