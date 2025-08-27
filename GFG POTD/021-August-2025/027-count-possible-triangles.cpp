// https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(N^3)
    // SC : O(1)
    int approach_1(vector<int> &arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        int trianglesCnt = 0;
        int i = 0, j = i + 1, k = j + 1;
        while (i < n - 2) {
            while (k < n) {
                if (arr[i] + arr[j] > arr[k]) {
                    trianglesCnt += 1;
                }
                k ++;
            }
            
            if (k == n && j < n - 2) {
                j += 1;
                k = j + 1;
            } else if (j == n - 2) {
                i += 1;
                j = i + 1;
                k = j + 1;
            }
        }
        return trianglesCnt;
    }
    
    // TC : O(N^2)
    // SC : O(1)
    int approach_2(vector<int> &arr) {
        int n = arr.size();
        
        sort(begin(arr), end(arr));
        int cntTriangles = 0;
        
        for (int k = n - 1; k >= 2; k --) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (arr[i] + arr[j] > arr[k]) {
                    cntTriangles += (j - i);
                    i ++;
                } else {
                    j --;
                }
            }
        }
        
        return cntTriangles;
    }
  public:
    int countTriangles(vector<int>& arr) {
        // return approach_1(arr);  // tle in java : O(N^3) due to simulation
        return approach_2(arr);
    }
};