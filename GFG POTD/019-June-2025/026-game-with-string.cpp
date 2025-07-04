// https://www.geeksforgeeks.org/problems/game-with-string4100/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N + K) ~= O(N)
    // SC : O(1)
    int minValue(string &s, int k) {
        vector<int> freq(26, 0);
        for (char &ch : s) {
            freq[ch - 'a'] ++;
        }
        
        priority_queue<int> pq;
        for (int &f : freq) {
            if (f > 0) {
                pq.push(f);
            }
        }
        
        while (k) {
            int num = pq.top();
            pq.pop();
            
            num -= 1;
            k   -= 1;
            
            pq.push(num);
        }
        
        int result = 0;
        while (!pq.empty()) {
            int num = pq.top();
            pq.pop();
            
            result += (num * num);
        }
        return result;
    }
};