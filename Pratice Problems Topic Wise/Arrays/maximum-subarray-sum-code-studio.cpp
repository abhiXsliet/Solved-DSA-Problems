// https://www.codingninjas.com/studio/problems/maximum-subarray-sum_630526



#include <bits/stdc++.h> 
using namespace std;
// TC => O(N) 
// SC => O(1)
// Using kadane's algorithm
long long maxSubarraySum(int arr[], int n)
{
    long long maxi = LONG_MIN;
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(sum > maxi) maxi = max(sum, maxi);
        if(sum < 0) {
            sum = 0;
        }
    }
    if(maxi < 0) return {};
    return maxi;
}