//

#include<bits/stdc++.h>
using namespace std;
//TC => O(N^3), SC => O(1)
int subArray( array<int, 10>& arr, int target) {
    int len = 0;
    for(int i=0; i<arr.size(); i++) {
        for(int j=i; j<arr.size(); j++) {
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum += arr[k];
            }

            if(sum == target) 
                len = max(len, j-i+1);
        }
    }
    return len;
}

// TC => O(N^2), SC => O(1)
int subArray2( array<int, 10>& arr, int target) {
    int len = 0;
    for(int i=0; i<arr.size(); i++) {
            int sum = 0;
        for(int j=i; j<arr.size(); j++) {
            sum += arr[j];
            if(sum == target) 
                len = max(len, j-i+1);
        }
    }
    return len;
}

// TC => O(N * log(N)), SC => O(N)
// Optimal code if the array has both +ve and -ve elements
int getLongestSubarray(array<int, 10>& a, int k){
    int len = 0;
    long long sum = 0;
    map<long long, int>hmap;
    for(int i=0; i<a.size(); i++) {
        sum += a[i];
        if(sum == k) {
            len = max(len, i+1);
        }

        int rem = sum - k;
        if(hmap.find(rem) != hmap.end()) {
            int newLen = i - hmap[rem];
            len = max(len, newLen);
        }
        //catch for 0's -> [2, 0, 0, 3]
        if(hmap.find(sum) == hmap.end()) {
            hmap[sum] = i;
        }
    }
    return len;
}

// This solution is optimal for only the +ve numbers including zeros
//TC => O(2N), SC => O(1)
int longestSubarrayWithSumK(array<int, 10>& a, long long k) {
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

int main() {
    cout << endl;
    array<int, 10>arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 10;
    cout << "Longest Sub-Array Length : " << subArray(arr, target) << endl;

    cout << "Longest Sub-Array Length : " << subArray2(arr, target) << endl;

    cout << "Longest Sub-Array Length : " << getLongestSubarray(arr, target) << endl;

    cout << "Longest Sub-Array Length : " << longestSubarrayWithSumK(arr, target) << endl;

    cout << endl;
    return 0;
}