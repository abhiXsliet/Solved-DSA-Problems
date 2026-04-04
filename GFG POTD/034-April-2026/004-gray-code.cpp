// https://www.geeksforgeeks.org/problems/gray-code-1611215248/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> graycode(int n) {
        vector<string> res;
        
        // base case
        res.push_back("0");
        res.push_back("1");
        
        for (int i = 2; i <= n; i++) {
            int size = res.size();
            
            // reverse order me traverse
            for (int j = size - 1; j >= 0; j--) {
                res.push_back(res[j]);
            }
            
            // first half → '0' prefix
            for (int j = 0; j < size; j++) {
                res[j] = "0" + res[j];
            }
            
            // second half → '1' prefix
            for (int j = size; j < 2 * size; j++) {
                res[j] = "1" + res[j];
            }
        }
        
        return res;
    }
};