// https://leetcode.com/problems/ipo/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(N)
    int approach_1(vector<int>& profits, vector<int>& capital, int k, int w) {
        int n = profits.size();
        vector<pair<int, int>> store(n);

        for (int i = 0; i < n; i ++) {
            store[i] = {capital[i], profits[i]};
        }

        sort(begin(store), end(store));

        priority_queue<int> pq;
        int index = 0;

        while (k --) {

            while (index < n && store[index].first <= w) {
                pq.push(store[index].second);   // push the profit into max-heap
                index ++;
            }

            if (pq.empty()) break;

            w += pq.top();
            pq.pop();
        }

        return w;
    }
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        return approach_1(profits, capital, k, w);
    }
};