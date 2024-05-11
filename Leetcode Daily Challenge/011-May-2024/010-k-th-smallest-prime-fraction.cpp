// https://leetcode.com/problems/k-th-smallest-prime-fraction/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef vector<double> V;

    // TC : O(N^2 * log(K))
    // SC : O(K)
    vector<int> approach_1(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result;
        priority_queue<vector<double>> pq;
        for (int i = 0; i < n - 1; i ++) {
            for (int j = i + 1; j < n; j ++) {
                
                double div = (double)arr[i]/arr[j];
                
                pq.push(vector<double>{div, (double)arr[i], (double)arr[j]});
                
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }
        auto vec = pq.top(); pq.pop();
        result.push_back(vec[1]);
        result.push_back(vec[2]);
        return result;
    }
    
    // TC : O(N^2 * log(K))
    // SC : O(K) 
    vector<int> approach_1_modified(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result;
        priority_queue<pair<double, pair<int, int>>> pq;
        for (int i = 0; i < n - 1; i ++) {
            for (int j = i + 1; j < n; j ++) {
                
                double div = (double)arr[i]/arr[j];
                
                pq.push({div, {arr[i], arr[j]}});
                
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }
        result.push_back(pq.top().second.first);
        result.push_back(pq.top().second.second);
        return result;
    }

    // TC : O((K + N)*log(N))
    // SC : O(N)
    vector<int> approach_2(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<V, vector<V>, greater<V>> pq;

        for (int i = 0; i < n; i++) {   // n - 1 will be largest
            pq.push({1.0*arr[i]/arr[n - 1], (double)i, (double)n - 1});
        }

        int smallest = 1;
        while(smallest < k) {
            V vec = pq.top();
            pq.pop();

            int i = vec[1];
            int j = vec[2] - 1;

            pq.push({1.0*arr[i]/arr[j], (double)i, (double)j});
            smallest ++;
        }

        V vec = pq.top();
        int i = vec[1];
        int j = vec[2];
        return {arr[i], arr[j]};
    }
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // return approach_1(arr, k);

        // return approach_1_modified(arr, k);

        return approach_2(arr, k);
    }
};