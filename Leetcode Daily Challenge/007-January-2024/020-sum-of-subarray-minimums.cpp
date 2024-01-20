// https://leetcode.com/problems/sum-of-subarray-minimums/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int M = 1e9 + 7;
    typedef unsigned long long ll;

    // Similar : Leetcode-84
    // TC : O(N^2)
    // SC : O(1)
    int solve_brute(vector<int>& arr) {
        int n = arr.size();
        long result = 0;

        for (int i = 0; i < n; i++) {
            
            int minVal = arr[i];
            for (int j = i; j < n; j++) {

                minVal = min(minVal, arr[j]);
                result = (result + minVal) % M;
            }
        }
        return result;
    }

    // TC : O(N)
    // SC : O(N)
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                result[i] = -1;
            } else {
                while(!st.empty() && arr[st.top()] > arr[i]) //strictly less
                    st.pop();
                
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    
    // TC : O(N)
    // SC : O(N)
    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                result[i] = n;
            } else {
                while(!st.empty() && arr[st.top()] >= arr[i]) //non-strictly less
                    st.pop();
                
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    
    // TC : O(N)
    // SC : O(N)
    int solve_optimal(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> NSL = getNSL(arr, n); //Next smaller to left
        vector<int> NSR = getNSR(arr, n); //Next smaller to right
        
        ll sum = 0;
        for(int i = 0; i<n; i++) {
            ll d1 = i - NSL[i]; //distance to nearest smaller to left from i
            
            ll d2 = NSR[i] - i; //distance to nearest smaller to right from i
            
            ll total_ways_for_i_min = d1 * d2;
            ll sum_i_in_total_ways  = arr[i] * (total_ways_for_i_min);
            
            sum  = (sum + sum_i_in_total_ways) % M;
        }
        return sum;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        // return solve_brute(arr);

        return solve_optimal(arr);
    }
};