// https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int isPossible(vector<int> &tasks, vector<int> &workers, int pills, int strength, int mid) {
        multiset<int> mst(begin(workers), begin(workers) + mid);
        int usedPills = 0;
        for (int i = mid - 1; i >= 0; i --) {
            int reqSt = tasks[i];
            auto it = prev(mst.end());

            if (*it >= reqSt) {
                mst.erase(it);
            } else if (usedPills >= pills) {
                return false;
            } else {
                auto bestSuitableWorker = mst.lower_bound(reqSt - strength);
                if (bestSuitableWorker == mst.end()) {
                    return false;
                }
                mst.erase(bestSuitableWorker);
                usedPills += 1;
            }
        }
        return true;
    }
public:
    // TC : O(NlogN + MlogM + min(M, N)*log(min(M, N))*log(min(M, N)))
    // SC : O(M)
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers), greater<int>());

        int low = 0, high = min(m, n);
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(tasks, workers, pills, strength, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};