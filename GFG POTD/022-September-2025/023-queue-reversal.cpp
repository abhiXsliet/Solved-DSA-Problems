// https://www.geeksforgeeks.org/problems/queue-reversal/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    void reverseQueue(queue<int> &q) {
        stack<int> stk;
        while (!q.empty()) {
            stk.push(q.front());
            q.pop();
        }
        while (!stk.empty()) {
            q.push(stk.top());
            stk.pop();
        }
    }
};