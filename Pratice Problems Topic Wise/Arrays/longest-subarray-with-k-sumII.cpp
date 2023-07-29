// https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_5713505


#include <bits/stdc++.h> 
using namespace std;
//Optimal code if the array has both +ve and -ve elements only.
//TC => O(N * log(N)), SC => O(N)
int getLongestSubarray(vector<int>& a, int k){
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