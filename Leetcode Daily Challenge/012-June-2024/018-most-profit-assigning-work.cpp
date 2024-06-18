// https://leetcode.com/problems/most-profit-assigning-work/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M*N) Where M = Total No. of workers available
    // SC : O(N)   Where N = Total No. of Profit or Difficulty
    int brute_1(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> profitDiff;
        int n = difficulty.size();
        int m = worker.size();
        
        for (int i = 0; i < n; i++) {
            profitDiff.push_back({profit[i], difficulty[i]});
        }

        sort(rbegin(profitDiff), rend(profitDiff));

        int result = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i < n && worker[i] >= profitDiff[j].second) {
                    result += profitDiff[j].first;
                    break;
                }
            }
        }
        return result;
    }

    // TC : O(M*N) Where M = Total No. of workers available
    // SC : O(1) Where N = Total No. of Profit or Difficulty
    int brute_2(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(),  m = worker.size(), result = 0;
        for (int i = 0; i < m; i ++) {
            int maxProfit    = 0;
            for (int j = 0; j < n; j ++) {
                if (i < n && worker[i] >= difficulty[j]) {
                    maxProfit = max(maxProfit, profit[j]);
                }
            }
            result += maxProfit;
        }
        return result;
    }

    // TC : O(N*log(N)) + O(M*log(M)) + O(M*log(N))
    // SC : O(N)
    int better(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size(), result = 0;

        priority_queue<pair<int, int>> pq; //MaxHeap

        for (int i = 0; i < n; i ++) {  // O(N*log(N))
            pq.push({profit[i], difficulty[i]});
        }

        sort(rbegin(worker), rend(worker)); // O(M*log(M))

        int idx = 0;
        while (idx < m && !pq.empty()) {    // O(M*log(N))
            if (worker[idx] < pq.top().second)
                pq.pop();
            else {
                result += pq.top().first;
                idx ++;
            }
        }

        return result;
    }

    // TC : O(N*log(N)) + O(M*log(N))
    // SC : O(N)
    int better_2(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size();

        vector<pair<int, int>> store;
        for (int i = 0; i < n; i ++) {
            store.push_back({difficulty[i], profit[i]});
        }

        // pre-calculating profits upto index i : so to get it in O(1)
        for (int i = 1; i < n; i ++) {
            store[i].second = max(store[i - 1].second, store[i].second);
        }

        sort(begin(store), end(store)); // O(N*log(N))

        int maxProfits = 0, totalProfits = 0;
        
        for (int i = 0; i < m; i ++) {
            int low = i, high = n - 1;
            while (low <= high) {   // log(N)
                int mid = (low + (high - low))/2;
                if (worker[mid] >= store[mid].first) {
                    maxProfits = max(maxProfits, store[mid].second);
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            totalProfits += maxProfits;
        }
        return totalProfits;
    }

    // TC : O(N*log(N)) + O(M*log(M)) + O(M + N)
    // SC : O(N)
    int optimal(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size();
        
        vector<pair<int, int>> store;
        for (int i = 0; i < n; i++) {
            store.push_back({difficulty[i], profit[i]});
        }

        sort(begin(store), end(store));     // O(N*log(N))
        sort(begin(worker), end(worker));   // O(M*log(M))

        int j = 0;  // pointing to store
        int totalProfit = 0, maxProfit = 0;
        
        for (int i = 0; i < m; i ++) {  // O(M + N)
            while (j < n && worker[i] >= store[j].first) {  
                maxProfit = max(maxProfit, store[j].second);
                j ++;
            }
            totalProfit += maxProfit;
        }
        return totalProfit;
    }
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // return brute_1(difficulty, profit, worker);

        // return brute_2(difficulty, profit, worker);

        // return better(difficulty, profit, worker);

        return optimal(difficulty, profit, worker);
    }
};