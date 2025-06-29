// https://www.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(M + Nlog(N) + Mlog(N))
    // SC : O(N)
    vector<int> approach_1(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        
        vector<int> newB = b;
        sort(begin(newB), end(newB));
        
        vector<int> result;
        for (int i = 0; i < m; i ++) {
            int idx = upper_bound(begin(newB), end(newB), a[i]) - begin(newB);
            result.push_back(idx);
        }
        return result;
    }
    
    // TC : O(M + N + maxi(a))
    // SC : O(maxi(a))
    vector<int> approach_2(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        
        int maxi = *max_element(begin(a), end(a));
        vector<int> prefix(maxi + 1, 0);
        
        for (int &num : b) {
            if (num <= maxi) prefix[num] ++;
        }
        
        for (int i = 1; i <= maxi; i ++) {
            prefix[i] += prefix[i - 1];
        }

        vector<int> result;
        for (int i = 0; i < m; i ++) {
            result.push_back(prefix[a[i]]);
        }
        return result;
    }
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // return approach_1(a, b);
        return approach_2(a, b);
    }
};