// https://www.codingninjas.com/studio/problems/ninja-and-the-zero-s_6581958


#include<bits/stdc++.h>
using namespace std;
vector<int> moveZeros(int n, vector<int> arr) {

/* 
    // TC : O(N)
    // SC : O(N)
    int left = 0; 
    int right = n - 1;
    int cnt = 0;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) 
            cnt++;
        if(arr[i] > 0)
            ans.push_back(arr[i]);
    }
    while(cnt--) {
        ans.push_back(0);
    }
    return ans;

     */

    // TC : O(N)
    // SC : O(1)
    int idx = 0;
    for(int i = 0; i < n; i++) {
        if(arr[idx] == 0 && arr[i] != 0) {
            swap(arr[idx], arr[i]);
            idx++;
        }
        if(arr[idx] != 0) idx++;
    }
    return arr;
    
}
