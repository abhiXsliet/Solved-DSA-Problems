// https://www.geeksforgeeks.org/problems/maximize-median-after-doing-k-addition-operation/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // check if we can make the median at least 
    // 'target' using at most 'k' operation
    bool isPossible(vector<int>& arr, int target, int k){
        int n = arr.size();
    
        if (n % 2 == 1) {
            // for odd-sized array, consider elements from 
            // middle to end
            for (int i = n / 2; i < n; ++i) {
                if (arr[i] < target)
                    k -= (target - arr[i]);
                if(k < 0) break;
            }
        } 
        else {
            // for even-sized array, handle two middle 
            // elements separately
            if (arr[n / 2] <= target) {
                k -= (target - arr[n / 2]);
                k -= (target - arr[n / 2 - 1]);
            } 
            else {
                k -= (2 * target - 
                        (arr[n / 2] + arr[n / 2 - 1]));
            }
            // process remaining elements to the right
            for (int i = n / 2 + 1; i < n; ++i) {
                if (arr[i] < target)
                    k -= (target - arr[i]);
                
                if(k < 0) break;
            }
        }
    
        return k >= 0;
    }
  public:
    int maximizeMedian(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
    
        // compute initial median floor if even length
        int iniMedian = arr[n / 2];
        if (n % 2 == 0) {
            iniMedian += arr[n / 2 - 1];
            iniMedian /= 2;
        }
    
        int low = iniMedian, high = iniMedian + k;
        int bestMedian = iniMedian;
    
        // binary search to find maximum 
        // achievable median
        while (low <= high) {
            int mid = (low + high) / 2;
    
            if (isPossible(arr, mid, k)) {
                bestMedian = mid;
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
    
        return bestMedian;
    }
};