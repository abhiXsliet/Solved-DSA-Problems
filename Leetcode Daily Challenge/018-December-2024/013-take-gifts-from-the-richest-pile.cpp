// https://leetcode.com/problems/take-gifts-from-the-richest-pile/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * log(N))
    // SC : O(N)
    long long approach_1(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for (int &gift : gifts) {
            pq.push(gift);
        }

        while (k --) {
            int maxValue = pq.top();
            pq.pop();
            pq.push(sqrt(maxValue));
        }

        long long remainingGifts = 0;
        while (!pq.empty()) {
            remainingGifts += pq.top();
            pq.pop();
        }
        return remainingGifts;
    }
public:
    long long pickGifts(vector<int>& gifts, int k) {
        return approach_1(gifts, k);
    }
};