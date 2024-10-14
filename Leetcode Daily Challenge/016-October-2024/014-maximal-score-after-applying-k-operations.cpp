// https://leetcode.com/problems/maximal-score-after-applying-k-operations/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N + K*log(N))
    // SC : O(N)
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq(begin(nums), end(nums)); // O(N) only in cpp heapify

        while (k --) {
            int topEl = pq.top();
            pq.pop();

            ans += topEl;

            pq.push( (topEl + 2) / 3 );
        }
        return ans;
    }
};