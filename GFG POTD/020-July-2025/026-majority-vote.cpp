// https://www.geeksforgeeks.org/problems/majority-vote/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        
        int ele1 = -1, ele2 = -1;
        int cnt1 =  0, cnt2 =  0;
        
        for (int &num : arr) {
            if (ele1 == num) cnt1 += 1;
            else if (ele2 == num) cnt2 += 1;
            else if (cnt1 == 0) {
                cnt1 = 1;
                ele1 = num;
            } else if (cnt2 == 0) {
                cnt2 = 1;
                ele2 = num;
            } else {
                cnt1 -= 1;
                cnt2 -= 1;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for (int &num : arr) {
            if (num == ele1) cnt1 += 1;
            if (num == ele2) cnt2 += 1; 
        }
        
        vector<int> result;
        if (cnt1 > n/3) result.push_back(ele1);
        if (cnt2 > n/3) result.push_back(ele2);
        sort(begin(result), end(result));
        return result;
    }
};