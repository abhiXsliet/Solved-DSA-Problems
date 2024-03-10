// https://leetcode.com/problems/last-stone-weight/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*log(N)) Where N = size of array of stones
    // SC : O(N)
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; // maxHeap
        for (auto& stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int el1 = pq.top(); pq.pop();
            int el2 = pq.top(); pq.pop();

            pq.push(el1 - el2);
        }

        if (pq.size() == 1) {
            int val = pq.top(); pq.pop();
            return val;
        }
        return 0;
    }
};