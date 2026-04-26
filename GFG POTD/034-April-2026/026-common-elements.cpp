// https://www.geeksforgeeks.org/problems/common-elements1132/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(l1 + l2 + l3)
    // SC : O(1)
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        int l1 = a.size(), l2 = b.size(), l3 = c.size();
        int i = 0, j = 0, k = 0;
        vector<int> result;
        
        while (i < l1 && j < l2 && k < l3) {
            while (i < l1 && (a[i] < b[j] || a[i] < c[k])) {
                i ++;
            }   
            while (j < l2 && (b[j] < a[i] || b[j] < c[k])) {
                j ++;
            }
            while (k < l3 && (c[k] < a[i] || c[k] < b[j])) {
                k ++;
            }
            while ((i < l1 && j < l2 && k < l3) && (a[i] == b[j] && b[j] == c[k])) {
                if (result.empty() || (!result.empty() && result.back() != a[i])) 
                    result.push_back(a[i]);
                i ++, j ++, k ++;
            }
        }
        
        return result;
    }
};