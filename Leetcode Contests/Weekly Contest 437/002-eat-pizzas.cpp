// https://leetcode.com/problems/eat-pizzas/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*log(N))
    // SC : O(1)
    long long maxWeight(vector<int>& pizzas) {
        int n = pizzas.size();
        sort (begin(pizzas), end(pizzas));

        int groups = n / 4;
        int oddGroups  = (groups + 1) / 2;
        int evenGroups = groups - oddGroups;

        long long ans = 0;
        int i = n - 1;
        while (i >= 0 && oddGroups --) {
            ans += pizzas[i --];
        }
        i --;

        // now take the elements from backward for Y (for even groups);
        while (i >= 0 && evenGroups --) {
            ans += pizzas[i];
            i -= 2;
        }
        return ans;
    }
};