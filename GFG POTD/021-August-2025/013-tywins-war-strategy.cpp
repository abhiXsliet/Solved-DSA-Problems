// https://www.geeksforgeeks.org/problems/tywins-war-strategy0527/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N * log(N))
    // SC : O(N)
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<>> pq;
        
        int reqMin = (n + 1) / 2;
        for (int &num : arr) {
            if (num % k == 0) {
                reqMin -= 1;
                if (reqMin == 0) return 0;
                continue;
            }
            
            int q = (num + k - 1) / k;  // ceil(num/k)
            pq.push(k*q - num);
        }
        
        int ans = 0;
        while (reqMin -- && !pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};