// https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> approach_1(vector<int> &a, vector<int> &b) {
        sort(begin(a), end(a));
        sort(begin(b), end(b));
        
        int m = a.size(), n = b.size();
        vector<int> result;
        int i = 0, j = 0;
        
        while (i < m && j < n) {
            while (i > 0 && a[i] == a[i - 1]) i ++;
            while (j > 0 && b[j] == b[j - 1]) j ++;
            if (i >= m || j >= n) break;
            
            if (a[i] == b[j]) {
                result.push_back(a[i]);
                i ++, j ++;
            } else if (a[i] < b[j]) {
                result.push_back(a[i]);
                i ++;
            } else {
                result.push_back(b[j]);
                j ++;
            }
        }
        
        while (i < m) {
            while (i > 0 && a[i] == a[i - 1]) i ++;
            if (i >= m) break;
            
            result.push_back(a[i]);
            i ++;
        }
        
        while (j < n) {
            while (j > 0 && b[j] == b[j - 1]) j ++;
            if (j >= n) break;
            
            result.push_back(b[j]);
            j ++;
        }
        
        return result;
    }
    vector<int> approach_2(vector<int> &a, vector<int> &b) {
        unordered_set<int> st(begin(a), end(a));
        st.insert(begin(b), end(b));
        return vector<int>(begin(st), end(st));
    }
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // return approach_1(a, b);
        return approach_2(a, b);
    }
};