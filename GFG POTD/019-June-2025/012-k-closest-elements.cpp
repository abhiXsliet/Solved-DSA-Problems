// https://www.geeksforgeeks.org/problems/k-closest-elements3619/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    using P = pair<int, int>;
    
    vector<int> genResult(vector<int> &arr, int k, int x, int i, int n) {
        int left = i - 1, right = (arr[i] == x) ? i + 1 : i;

        vector<int> result;
        while (left >= 0 && right < n && result.size() < k) {
            int lDiff = abs(arr[left] - x);
            int rDiff = abs(arr[right]- x);
            
            if (lDiff >= rDiff) {
                result.push_back(arr[right ++]);
            } else {
                result.push_back(arr[left --]);
            }
        }
        while (left >= 0 && result.size() < k) {
            result.push_back(arr[left --]);
        }
        while (right < n && result.size() < k) {
            result.push_back(arr[right ++]);
        }
        return result;
    }
    
    // TC : O(N * log(N))
    // SC : O(K)
    vector<int> approach_1(vector<int> &arr, int k, int x) {
        int n = arr.size();
        auto cmp = [&](P a, P b) {
            if (a.first == b.first) {
                return b.second < a.second;
            }  
            return b.first > a.first;
        };
        priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; i ++) {
            int val = abs(arr[i] - x);
            if (val == 0) continue;
            if (pq.size() < k) {
                pq.push({val, arr[i]});
            } else {
                if ((pq.top().first > val) || (pq.top().first == val && pq.top().second < arr[i])) {
                    pq.pop();
                    pq.push({val, arr[i]});
                }  
            }
        }
        vector<int> result(k);
        int idx = k - 1;
        while (!pq.empty()) {
            result[idx --] = pq.top().second;
            pq.pop();
        }
        return result;
    }
    
    // TC : O(N)
    // SC : O(K)
    vector<int> approach_2(vector<int> &arr, int k, int x) {
        int n = arr.size();
        int i = 0;
        while (i < n && arr[i] < x) i ++;
        
        return genResult(arr, k, x, i, n);
    }
    
    // TC : O(log(N) + K)
    // SC : O(K)
    vector<int> approach_3(vector<int> &arr, int k, int x) {
        int n = arr.size();
        int i = lower_bound(begin(arr), end(arr), x) - begin(arr);
        
        return genResult(arr, k, x, i, n);
    }
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // return approach_1(arr, k, x);    // BRUTE
        // return approach_2(arr, k, x);    // BETTER
        return approach_3(arr, k, x);    // OPTIMAL
    }
};