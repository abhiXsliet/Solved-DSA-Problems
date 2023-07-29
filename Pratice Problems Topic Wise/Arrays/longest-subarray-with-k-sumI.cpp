//


#include<bits/stdc++.h>
using namespace std;

// This solution is optimal for only the +ve numbers
//TC => O(2N), SC => O(1)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int len = 0;
    long long sum = a[0];
    int left = 0;
    int right= 0;

    while(right < a.size()) {
        while(left <= right && sum > k) {
            sum -= a[left++];
        }
        if(sum == k) len = max(len, right - left + 1);
        if(right < a.size()) sum += a[++right];
    }
    return len;
}