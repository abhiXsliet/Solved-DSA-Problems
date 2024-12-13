// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/



#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    typedef long long ll;
    typedef pair<int, int> P;

    // TC : O(N*log(N))
    // SC : O(N)
    ll approach_1(vector<int>& nums) {
        int n  = nums.size();
        priority_queue<P, vector<P>, greater<P>> pq;
        for (int i = 0; i < n; i ++) {
            pq.push({nums[i], i});
        }

        vector<int> marked(n, 0);

        ll res = 0;
        while (!pq.empty()) {
            P it = pq.top();
            pq.pop();

            if (!marked[it.second]) {
                marked[it.second] = 1;
                if (it.second + 1 < n) 
                    marked[it.second + 1] = 1;
                if (it.second - 1 >= 0)
                    marked[it.second - 1] = 1;

                res += it.first;
            }
        }
        return res;
    }
public:
    ll findScore(vector<int>& nums) {
        return approach_1(nums);
    }
};