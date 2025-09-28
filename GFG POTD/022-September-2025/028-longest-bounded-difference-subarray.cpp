// https://www.geeksforgeeks.org/problems/longest-bounded-difference-subarray/1/




#include <bits/stdc++.h>
using namespace std;


class Solution {
  private:
    using P = pair<int, int>;
    
    // TC : O(N*log(N))
    // SC : O(N)
    vector<int> approach_1(vector<int>& arr, int x) {
        int n = arr.size();
        priority_queue<P, vector<P>, greater<P>> mnH;
        priority_queue<P> mxH;
        int maxLen = 0;
        int start  = 0;
        int i = 0, j = 0;
        while (j < n) {
            mnH.push({arr[j], j});
            mxH.push({arr[j], j});
            while (abs(mnH.top().first - mxH.top().first) > x) {
                while (!mnH.empty() && mnH.top().second <= i) mnH.pop();
                while (!mxH.empty() && mxH.top().second <= i) mxH.pop();
                i ++;
            }
            if (j - i + 1 > maxLen) {
                maxLen = (j - i + 1);
                start  = i;
            }
            j ++;
        }
        vector<int> result;
        for (int i = start; i < maxLen + start; i ++) {
            result.push_back(arr[i]);
        }
        return result;
    }
    
    // TC : O(N)
    // SC : O(N)
    vector<int> approach_2(vector<int>& arr, int x) {
        int n = arr.size();
        deque<int> mnDq, mxDq;
        int maxLen = 0;
        int start  = 0;
        int i = 0, j = 0;
        while (j < n) {
            while (!mnDq.empty() && arr[j] <= arr[mnDq.back()]) { // curr element is smaller than minQ back
                mnDq.pop_back();
            }
            while (!mxDq.empty() && arr[j] >= arr[mxDq.back()]) { // curr element is greater than maxQ back
                mxDq.pop_back();
            }
            
            mnDq.push_back(j);
            mxDq.push_back(j);
            
            while (abs(arr[mxDq.front()] - arr[mnDq.front()]) > x) {
                if (mnDq.front() == i) mnDq.pop_front();    // catch
                if (mxDq.front() == i) mxDq.pop_front();
                i ++;
            }
            if (j - i + 1 > maxLen) {
                maxLen = (j - i + 1);
                start  = i;
            }
            j ++;
        }
        vector<int> result;
        for (int i = start; i < maxLen + start; i ++) {
            result.push_back(arr[i]);
        }
        return result;
    }
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // return approach_1(arr, x);
        return approach_2(arr, x);
    }
};