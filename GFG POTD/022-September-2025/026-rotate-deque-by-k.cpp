// https://www.geeksforgeeks.org/problems/rotate-deque-by-k/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    void rotateDeque(deque<int>& dq, int type, int k) {
        while (k --) {
            if (type == 1) {
                int val = dq.back();
                dq.pop_back();
                dq.push_front(val);
            } else {
                int val = dq.front();
                dq.pop_front();
                dq.push_back(val);
            }
        }
    }
};