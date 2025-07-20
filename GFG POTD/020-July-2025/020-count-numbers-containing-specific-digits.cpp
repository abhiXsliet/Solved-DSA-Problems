// https://www.geeksforgeeks.org/problems/count-numbers-containing-specific-digits/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(1)
    // SC : O(1)
    int countValid(int n, vector<int>& arr) {
        unordered_set<int> st;
        bool isZero = false;
        for (int &v : arr) {
            if (v != 0) {
                st.insert(v);
            } else isZero = true;
        }
        int size  = st.size();
        int badNo = 9 - size;
        int val   = badNo + ((isZero) ? 0 : 1);
        int total = 9;
        for (int i = 1; i < n; i ++) {
            total *= 10;
            badNo *= (val);
        }
        return total - badNo;
    }
};
