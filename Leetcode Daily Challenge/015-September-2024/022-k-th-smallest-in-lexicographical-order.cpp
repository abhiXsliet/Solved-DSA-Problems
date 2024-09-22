// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    int counter = 0;
    int result  = 0;

    // TC : O(N)
    // SC : O(digits)
    bool solve(ll num, int n, int k) {
        if (num  > n) return false;

        counter ++;

        if (counter == k) {
            result = num;
            return true;
        }

        for (int append = 0; append <= 9; append ++) {
            ll newN = (num * 10) + append;
            if (newN > n) break;

            if (solve(newN, n, k))
                return true;
        }
        return false;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(int n, int k) {
        for (ll i = 1; i <= 9; i ++) {
            if(solve(i, n, k)) {
                break;
            }
        }
        return result;
    }

    // TC : O(log(N)) Where N = No. of digits in N
    // SC : O(1)
    int counting(long curr, long next, int n) {
        int countNum = 0;
        while (curr <= n) {
            countNum += (next - curr);

            curr *= 10;
            next = min(next*10, (long)n + 1);     // CATCH
        }
        return countNum;
    }

    // TC : O(log(N) * log(N)) Where N = No. of digits in N
    // SC : O(1)
    int approach_3(int n, int k) {
        int curr = 1;
        k -= 1; // starting from 1st element (1) : left with only (k - 1) elements to search
        while (k > 0) {
            int next = curr + 1;
            int countSum = counting(curr, next, n); // counting sum of prefixes lexiographically

            if (countSum <= k) {    // different subtree, need to change the subtree
                curr ++;
                k -= countSum;  // skipping elements under current prefix tree

            } else {        // need to go in depth of the same tree
                k -= 1;
                curr *= 10;
            }
        }
        return curr;
    }
public:
    int findKthNumber(int n, int k) {
        // return approach_1(n, k);    // MLE : generate & store all numbers lexiographically, return the kth number
        // return approach_2(n, k);    // TLE 
        return approach_3(n, k);
    }
};