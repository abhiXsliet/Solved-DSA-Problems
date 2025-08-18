// https://www.geeksforgeeks.org/problems/find-h-index--165609/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // is it possible to have tar-index as H-index with citations >= tar
    bool isPossible(vector<int> &citations, int n, int tar) {
        int count = 0;
        for (int &val : citations) {
            if (val >= tar) {
                count += 1;
            }
        }
        return count >= tar;
    }
    
    // TC : O(N * log(N))
    // SC : O(1)
    int approach_1(vector<int> &citations) {
        int n = citations.size();
        int low = 0, high = *max_element(begin(citations), end(citations));
        int ans = low;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(citations, n, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int> &citations) {
        int n = citations.size();
        
        vector<int> citationSum(n + 1, 0);
        for (int &val : citations) {
            if (val <= n) {
                citationSum[val] ++;
            } else {
                citationSum[n] += 1;
            }
        }
        
        int hIndex = 0;
        for (int i = n; i >= 0; i --) {
            citationSum[i] += (i == n) ? 0 : citationSum[i + 1];
            if (citationSum[i] >= i) {
                hIndex = i;
                break;
            }
        }
        return hIndex;
    }
  public:
    int hIndex(vector<int>& citations) {
        // return approach_1(citations);
        return approach_2(citations);  
    }
};